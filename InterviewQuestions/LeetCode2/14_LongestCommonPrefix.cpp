/********************************************************************
* Write a function to find the longest common prefix string amongst an array of strings. 
********************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n1 + n2 + ...), Space: O(1) */
	string longestCommonPrefix1(vector<string> &strs) {
		if (strs.empty()) {
			return "";
		}
		
		string commonStr("");
		for (int i = 0; i < strs[0].length(); i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (strs[j][i] != strs[0][i]) {
					 // Even element on position i is not satisfied,
					 // but the i is from 0, so the length should be i (-1)
					return strs[0].substr(0, i);
				}
			}
		}
		
		return strs[0];
	}
	
	/* Time: O(n1 + n2 + ...), Space: O(1) */
	string longestCommonPrefix2(vector<string> &strs) {
		if (strs.empty()) {
			return string("");
		}
		
		int right_most = strs[0].length();
		for (int i = 1; i < strs.size(); i++) {
			for (int j = 0; j < right_most; j++) {
				if (strs[i][j] != strs[0][j]) {
					right_most = j;
					break;
				}
			}
		}
		
		return strs[0].substr(0, right_most);
	}
};

int main(void) {
	Solution *s = new Solution();
	string s1 = "abcdefgh";
	string s2 = "abcdabcd";
	string s3 = "abc";
	
	vector<string> strs { s1, s2, s3 };
	
	cout << "Solution 1: " << s->longestCommonPrefix1(strs) << endl;
	cout << "Solution 1: " << s->longestCommonPrefix2(strs) << endl;
	
	delete s;
	return 0;
}