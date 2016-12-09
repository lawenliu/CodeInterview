/******************************************
* Given a string s, partition s such that ever substring of the 
* partition is a palindrome.
* Return all possible palindrome partitioning of s.
* For example, given s = "aab", Return
*  [
* 	 ["aa", "b"],
* 	 ["a", "a", "b"]
*  ]
******************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	bool isPalindrome(string s, int start, int end) {
		while (start < end && s[start] == s[end]) {
			start++;
			end--;
		}
		
		return start >= end;
	}
	
	void partitionAux(string s, vector<string> &path, vector<vector<string>> &result, int prev, int start) {
		if (start == s.size()) {
			if (isPalindrome(s, prev, start - 1)) {
				path.push_back(s.substr(prev, start - prev));
				result.push_back(path);
				path.pop_back();
			}
			
			return;
		}
		
		partitionAux(s, path, result, prev, start + 1);
		if (isPalindrome(s, prev, start - 1)) {
			path.push_back(s.substr(prev, start - prev));
			partitionAux(s, path, result, start, start + 1);
			path.pop_back();
		}
	}
public:
	/* Time: O(2^n), Space: O(n) */
	/* brute-force */
	vector<vector<string>> partition1(string s) {
		vector<vector<string>> result;
		vector<string> path;
		partitionAux(s, path, result, 0, 1);
		return result;
	}
	
	/* Time: O(n^2), Space: O(n) */
	/* dynamic programming */
	vector<vector<string>> partition2(string s) {
		const int n = s.size();
		vector<vector<bool>> p(n, vector<bool>(n, false));
		
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				p[i][j] = s[i] == s[j] && (j - i < 2 || p[i+1][j-1]);
			}
		}

		vector<vector<vector<string>>> subPalindromes(n, vector<vector<string>>());
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (p[i][j]) {
					const string palindrome = s.substr(i, j - i + 1);
					if (j + 1 < n) {
						vector<vector<string>> subPalindrome;
						for (auto p : subPalindromes[j+1]) {
							p.insert(p.begin(), palindrome);
							subPalindromes[i].push_back(p);
						}
					} else {
						subPalindromes[i].push_back(vector<string> { palindrome });
					}
				}
			}
		}
		
		return subPalindromes[0];
	}
};

int main(void) {
	Solution* s = new Solution();
	string ss = "aab";
	
	cout << "Solution 1:" << endl;
	vector<vector<string>> result = s->partition1(ss);
	for (int i = 0; i < result.size(); i++) {
		cout << "Partition" << i + 1 << ": ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	cout << "Solution 2:" << endl;
	result = s->partition2(ss);
	for (int i = 0; i < result.size(); i++) {
		cout << "Partition" << i + 1 << ": ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}