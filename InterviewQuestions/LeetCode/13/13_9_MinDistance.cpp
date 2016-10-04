/************************************
* Given two words word1 and word2, find the minimum number of steps required to convert word1
* to word2. (each operation is counted as 1 steps.)
* You have the following 3 operation permitted on a word:
* 1. Insert a character
* 2. Delete a character
* 3. Replace a characer
************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(m * n), Space: (m * n) */
	int minDistance(const string &word1, const string &word2) {
		const int m = word1.size();
		const int n = word2.size();
		vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; i++) {
			f[i][0] = i;
		}
		
		for (int j = 0; j <= n; j++) {
			f[0][j] = j;
		}
		
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i-1] == word2[j-1]) {
					f[i][j] = f[i-1][j-1];
				} else {
					f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
				}
			}
		}
		
		return f[m][n];
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "abcdefg";
	string s2 = "dfaadded";
	string s3 = "";
	
	cout << "Solution 1: " << s->minDistance(s1, s2) << endl;
	cout << "Solution 1: " << s->minDistance(s1, s3) << endl;
	
	delete s;
	return 0;
}
