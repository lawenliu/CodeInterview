/**********************************
* Given a string S and a string T, count the number of distinct subsequences of T in S.
* A subsequence of a string is a new string which is formed from the original string by deleting some
* (can be none) of the characers without disturbing the relative position of the remaining characters.
* (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
* Here is an example: S = "rabbbit", T = "rabbit" return 3.
**********************************/
#include <iostream>
#include <vector>
using namespace std;

/******************
1 * 0 0 0 0 0 0
* * r a b b i t
1 r 1 0 0 0 0 0
1 a 1 1 0 0 0 0
1 b 1 1 1 0 0 0
1 b 1 1 2 1 0 0
1 b 1 1 3 3 0 0
1 i 1 1 3 3 3 0
1 t 1 1 3 3 3 3

******************/
class Solution {
public:
  /* Time: O(m*n), Space: O(m * n) */
	int numDistinct1(const string &s, const string &t) {
		const int m = s.size();
		const int n = t.size();
		vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
		
		for (int i = 0; i < m + 1; i++) {
			f[i][0] = 1;
		}
		
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				f[i][j] = s[i-1] != t[j-1] ? f[i-1][j] : f[i-1][j] + f[i-1][j-1];
			}
		}
		
		return f[m][n];
	}
	
	/* Time: O(m*n), Space: O(n) */
	int numDistinct2(const string &s, const string &t) {
		const int m = s.size();
		const int n = t.size();
		vector<int> f(n + 1);
		f[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = n - 1; j >= 0; j--) {
				f[j+1] += s[i] == t[j] ? f[j] : 0;
			}
		}
		
		return f[n];
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "rabbbit";
	string t1 = "rabbit";
	
	cout << "Solution 1: " << s->numDistinct1(s1, t1) << endl;
	cout << "Solution 2: " << s->numDistinct2(s1, t1) << endl;
	
	delete s;
	return 0;
}