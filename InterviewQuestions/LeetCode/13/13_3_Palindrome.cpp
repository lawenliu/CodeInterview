/*************************************
* Given a string s, partition s such that every substring of the partition is a palindrome.
* Return the minimum cuts needed for a palindrome partitioning of s.
* For example, given s = "aab", Return 1 since the palindrome partitioning ["aa", "b"] could
* be produced using 1 cut.
*************************************/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
	int checkPalindrome(const string &s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right && s[left] == s[right]) {
			left++;
			right--;
		}
		
		return (left >= right);
	}
	
public:
	/* Time: O(*), Space: O(1) */
	int minCut1(const string &s) {
		if (checkPalindrome(s)) {
			return 0;
		}
		
		int minCut = s.size() - 1;
		for (int i = 1; i < s.size(); i++) {
			int left = minCut1(s.substr(0, i));
			int right = minCut1(s.substr(i, s.size() - i));
			minCut = min(minCut, left + right + 1);
		}
		
		return minCut;
	}
	
	/* Time: O(n^2), Space: O(n^2)
		f(i) = min{f(j + 1) + 1)}, 0 <= i <= j < n,
		p[i][j] = str[i] == str[j] && p[i+1][j-1] */
	int minCut2(const string &s) {
		const int n = s.size();
		int* f = new int[n + 1];
		bool** p = new bool*[n];
		for (int i = 0; i < n; i++) {
			p[i] = new bool[n];
			for (int j = 0; j < n; j++) {
				p[i][j] = false;
			}
		}
		// The worst case is cutting by each char
		for (int i = 0; i <= n; i++) {
			f[i] = n - 1 - i;
		}
		
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
					f[i] = min(f[i], f[j + 1] + 1);
					p[i][j] = true;
				}
			}
		}
		
		int minCut = f[0];
		
		delete []f;
		for (int i = 0; i < n; i++) {
			delete []p[i];
		}
		delete []p;
		return minCut;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s0 = "aab";
	string s1 = "abcabcbb";
	string s2 = "bbbbb";
	string s3 = "abcdefg";
	
	cout << "Solution 1: " << s->minCut1(s0) << endl;
	cout << "Solution 1: " << s->minCut1(s1) << endl;
	cout << "Solution 1: " << s->minCut1(s2) << endl;
	cout << "Solution 1: " << s->minCut1(s3) << endl;
	cout << "Solution 2: " << s->minCut2(s0) << endl;
	cout << "Solution 2: " << s->minCut2(s1) << endl;
	cout << "Solution 2: " << s->minCut2(s2) << endl;
	cout << "Solution 2: " << s->minCut2(s3) << endl;
		
	delete s;
	return 0;
}