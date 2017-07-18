/*******************************************************************
* Given a string S, find the longest palindromic substring in S.
* You may assume that the maximum length of S is 1000, and there
* exists one unique longest palindromic substring.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Substring {
	int start;
	int end;
};

class Solution {
public:
	/* Time: O(n^2), Space: O(1) */
	/* Brute-force */
	string longestPalindrome1(const string &s) {
		int longestStart = 0;
		int longestEnd = 0;
		int longestLen = 0;
		
		for (int i = 0; i < s.length(); i++) {
			// s[i] as the center, such as "abcba" for "c"
			int j = i, k = i;
			while (j >= 0 && k < s.length() && s[j] == s[k]) {
				j--;
				k++;
			}
			
			int len = (k - 1) - (j + 1) + 1;
			if (len > longestLen) {
				longestLen = len;
				longestStart = j + 1;
				longestEnd = j - 1;
			}
			
			// s[i] and s[i+1] as the center, such as "abccba" for "cc"
			j = i, k = i + 1;
			while (j >= 0 && k < s.length() && s[j] == s[k]) {
				j--;
				k++;
			}
			
			len = (k - 1) - (j + 1) + 1;
			if (len > longestLen) {
				longestLen = len;
				longestStart = j + 1;
				longestEnd = k - 1;
			}
		}
		
		return s.substr(longestStart, longestLen);
	}
	
	/* Time: O(n^2), Space: O(n^2) */
	/* f[i][j] = (i == j) ? S[i] :
								(S[i] == S[j] && f[i+1][j-1] == S[i+1][j-1] ? S[i][j] :
															max(f[i+1][j-1], f[i][j-1], f[i+1][j])
		S[i][j] is substring of  s from i to j; f[i][j] is longest palindrome substring
			between i and j;
		Memory reused.
	*/
	string longestPalindrome2(const string &s) {
		vector<vector<Substring>> f(s.length(), vector<Substring>(s.length()));
		Substring maxSubstring;
		for (int j = 0; j < s.length(); j++) {
			for (int i = j; i >= 0; i--) {
				if (i == j) {
					Substring str;
					str.start = i;
					str.end = j;
					f[i][j]  = str;
				} else if (s[i] == s[j] && ((f[i+1][j-1].start == i + 1 && f[i+1][j-1].end == j - 1) || i == j-1)) {
					Substring str;
					str.start = i;
					str.end = j;
					f[i][j] = str;
				} else {
					Substring str;
					if (f[i+1][j-1].end - f[i+1][j-1].start > f[i][j-1].end - f[i][j-1].start) {
						str.start = f[i+1][j-1].start;
						str.end = f[i+1][j-1].end;
					} else {
						str.start = f[i][j-1].start;
						str.end = f[i][j-1].end;
					}
					
					if (str.end - str.start < f[i+1][j].end - f[i+1][j].end) {
						str.start = f[i+1][j].start;
						str.end = f[i+1][j].end;
					}
					
					f[i][j] = str;
				}
			}
		}
		
		return s.substr(f[0][s.length()-1].start, f[0][s.length()-1].end - f[0][s.length()-1].start + 1);
	}
	
	/* Time: O(n^2), Space: O(n^2) */
	/* f[i][j] = (i == j) ? true :
													(j == i + 1) ? S[i] == S[j] :
																				(j > i + 1) ? S[i] == S[j] && f[i+1][j-1] : fasle;
			f[i][j] is flag to say whether the substring from i to j is palindrome.
			Dynamic Programming
	*/
	string longestPalindrome3(const string &s) {
		vector<vector<bool>> f(s.length(), vector<bool>(s.length(), false));
		
		for (int j = 0; j < s.length(); j++) {
			for (int i = j; i >= 0; i--) {
				if (i == j) {
					f[i][j] = true;
				} else if (s[i] == s[j] && (f[i+1][j-1] || i == j - 1)) {
					f[i][j] = true;
				} else {
					f[i][j] = false;
				}
			}
		}
		
		int maxStart = 0, maxLen = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < s.length(); j++) {
				if (f[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					maxStart = i;
				}
			}
		}
		
		return s.substr(maxStart, maxLen);
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "abba";
	string s2 = "klsdlabbaoowddo";
	string s3 = "abcba";
	string s4 = "klsdlabcbaoowddo";
	
	cout << "Solution 1: " << s->longestPalindrome1(s1) << endl;
	cout << "Solution 1: " << s->longestPalindrome1(s2) << endl;
	cout << "Solution 1: " << s->longestPalindrome1(s3) << endl;
	cout << "Solution 1: " << s->longestPalindrome1(s4) << endl;
	
	cout << "Solution 2: " << s->longestPalindrome2(s1) << endl;
	cout << "Solution 2: " << s->longestPalindrome2(s2) << endl;
	cout << "Solution 2: " << s->longestPalindrome2(s3) << endl;
	cout << "Solution 2: " << s->longestPalindrome2(s4) << endl;

	cout << "Solution 3: " << s->longestPalindrome3(s1) << endl;
	cout << "Solution 3: " << s->longestPalindrome3(s2) << endl;
	cout << "Solution 3: " << s->longestPalindrome3(s3) << endl;
	cout << "Solution 3: " << s->longestPalindrome3(s4) << endl;
	
	delete s;
	return 0;
}