/**********************************
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (
* you may want to display this pattern in a fixed font for better legibility)
*    P   A   H   N
*    A P L S I I G
*    Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:
*        string convert(string text, int nRows)
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(n) */
	/*  n = 4:
		*  P     I     H
		*  A   L S   I G
		*  Y A   H R
		*  P     I
	*/
	/*  n = 5:
		*  P       H
		*  A     S I
		*  Y   I   R
		*  P L     I G
		*  A       N
	*/
	string convert1(string s, int nRows) {
		vector<vector<char>> lines(nRows, vector<char>());
		int index = 0;
		while (index < s.length()) {
			for (int j = 0; j < nRows && index < s.length(); j++) {
				lines[j].push_back(s[index]);
				index++;
			}
			
			for (int j = nRows - 2; j > 0 && index < s.length(); j--) {
				lines[j].push_back(s[index]);
				index++;
			}
		}
		
		string result;
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < lines[i].size(); j++) {
				result.append(1, lines[i][j]);
			}
		}
		
		return result;
	}
	
	/* Time: O(n), Space: O(1) */
	/*                   */
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "PAYPALISHIRING";
	
	cout << "Solution 1: " << s->convert1(s1, 3) << endl;
	cout << "Solution 1: " << s->convert1(s1, 4) << endl;
	cout << "Solution 1: " << s->convert1(s1, 5) << endl;
	
	delete s;
	return 0;
}