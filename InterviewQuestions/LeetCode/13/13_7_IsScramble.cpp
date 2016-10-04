/***********************************
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
* Below is one possible representation of s1 == "great":
*              great
*            /       \
*           gr       eat
*          /  \     /   \
*         g    r   e     at
*                       /  \
*                      a    t
* To scramble the string, we may choose any non-leaf node and swap its two children.
* Fo eaxample, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
*              rgeat
*            /       \
*           rg       eat
*          /  \     /   \
*         r    g   e     at
*                       /  \
*                      a    t
* We say that "rgeat" is a scrambled string of "great".
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
*              rgtae
*            /       \
*           rg       tae
*          /  \     /   \
*         r    g    ta   e
*                  /  \
*                 t    a
* We say that "rgtae" is a scrambled string of "great".
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
***********************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	
	/* Time: O(n^6), Space(1) */
	bool isScramble1(const string &s1, const string &s2) {
		if (s1.size() != s2.size()) {
			return false;
		}
		
		if (s1.size() == 0 && s2.size() == 0) {
			return true;
		}
		
		if (s1.size() == 1) {
			return s1[0] == s2[0];
		}
		
		for (int i = 1; i < s1.size(); i++) {
			if ((isScramble2(s1.substr(0, i), s2.substr(0, i))
				&& isScramble2(s1.substr(0, i), s2.substr(s2.size() - i - 1, i)))
					|| (isScramble2(s1.substr(i, s1.size() - i - 1), s2.substr(0, s2.size() - i - 1))
							&& isScramble2(s1.substr(i, s1.size() - i - 1), s2.substr(i, s1.size() - i - 1)))) {
								return true;
			}
			
			return false;
		}
	}
	
	/* Time: O(n^3), Space: O(n^3) */
	/* f[n][i][j] = (f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j]) 
			f[n][i][j] says s1 started from i and s2 started from j taking n length are scramble with each other */
	bool isScramble2(const string &s1, const string &s2) {
		if (s1.size() != s2.size()) {
			return false;
		}
		
		if (s1.size() == 0 && s2.size() == 0) {
			return true;
		}
		
		if (s1.size() == 1) {
			return s1[0] == s2[0];
		}
		
		const int n = s1.size();
		vector<vector<vector<bool>>> f(n + 1, vector<vector<bool>>(n, vector<bool>(n, true)));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				f[1][i][j] = s1[i] == s2[j];
			}
		}
		
		for (int pivot = 1; pivot < n; pivot++) {
			for (int i = 0; i + pivot <= n; i++) {
				for (int j = 0; j + pivot <= n; j++) {
					for (int k = 1; k < pivot; k++) {
						if ((f[k][i][j] && f[pivot-k][i+k][j+k]) ||
							(f[k][i][j+pivot-k] && f[pivot-k][i+k][j])) {
								f[pivot][i][j] = true;
								break;
							}
					}
				}
			}
		}
		
		return f[n][0][0];
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "greating";
	string s2 = "rngeagti";
	string s3 = "rggtaien";
	
	cout << "Solution 1: " << s->isScramble1(s1, s2) << endl;
	cout << "Solution 1: " << s->isScramble1(s1, s3) << endl;
	cout << "Solution 2 " << s->isScramble2(s1, s2) << endl;
	cout << "Solution 2: " << s->isScramble2(s1, s3) << endl;
	
	delete s;
	return 0;
}