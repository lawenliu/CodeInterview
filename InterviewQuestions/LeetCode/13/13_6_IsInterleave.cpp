/*********************************
* Given s1, s2, s3, find whether s3 is formed by the interleave of s1 and s2.
* For example, Given: s1 = "aabcc", s2 = "dbbca",
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
*********************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(2^n) --- s1="aaaa", s2="aaaa", s3="aaaaaaaa", Space: O(1) */
	bool isInterleave1(const string &s1, const string &s2, const string &s3) {
		if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) {
			return true;
		}
		
		bool isInterleave = false;
		if(s1.size() != 0 && s3.size() != 0 && s1[0] == s3[0]) {
			isInterleave = isInterleave1(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1));
		}
		
		if(s2.size() != 0 && s3.size() != 0 && s2[0] == s3[0]) {
			isInterleave = isInterleave1(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
		}
		
		return isInterleave;
	}
	
	/* Time: O(n^2), Space: O(n^2) */
	bool isInterleave2(const string & s1, const string &s2, const string &s3) {
		if (s1.size() + s2.size() != s3.size()) {
			return false;
		}
		
		vector<vector<bool>> f(s1.size() + 1, vector<bool>(s2.size() + 1, true));
		for (int i = 1; i <= s1.size(); i++) {
			f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
		}
		
		for (int i = 1; i <= s2.size(); i++) {
			f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		}
		
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
			f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
								|| (s2[j - 1] == s3[i + j - 1] &&f[i][j - 1]);
			}
		}
		
		return f[s1.size()][s2.size()];
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s31 = "aadbbcbcac";
	string s32 = "aadbbbaccc";
	
	cout << "Solution 1: " << s->isInterleave1(s1, s2, s31) << endl;
	cout << "Solution 1: " << s->isInterleave1(s1, s2, s32) << endl;
	cout << "Solution 2: " << s->isInterleave2(s1, s2, s31) << endl;
	cout << "Solution 2: " << s->isInterleave2(s1, s2, s32) << endl;
	
	delete s;
	return 0;
}