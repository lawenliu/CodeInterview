/**********************************************************
* The string "PAYPALISHIRING" is written in a zigzag pattern
* on a given number of rows like this: (you may want to 
* display this pattern in a fixed font for better legibility)
*  P   A   H   N
*  A P L S I I G
*  Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this 
* conversion given a number of rows:
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(n) */
	/* n = 4:
		* P     I     N
		* A   L S   I G
		* Y A   H R 
		* P     I
		*
		* n = 5:
		* P       H
		* A     S I
		* Y   I   R
		* P L     I G
		* A       N
		*/
	string convert1(string s, int nRows) {
		vector<vector<char>> lines(nRows, vector<char>());
		int index = 0;
		while (index < s.length()) {
			for (int j = 0; j < nRows && index < s.length(); j++, index++) {
				lines[j].push_back(s[index]);
			}
			
			for (int j = nRows - 2; j > 0 && index < s.length(); j--, index++) {
				lines[j].push_back(s[index]);
			}
		}
		
		string result;
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < lines[i].size(); j++) {
				result.append(1, lines[i][j]); // result += lines[i][j];
			}
		}
		
		return result;
	}
	
	/* Time: O(n), Space: O(1) */
	/*
	* lets consider the position of the letters:
	* 1. the index of the letter on each row: 0 ~ nRows of the string
	* 2. the D-value of index between each following columns except the diagonal line: 2 * nRows - 2
	* 3. the index of diagonal line is jj + 2 * nRows - 2 - 2 * i, jj is the last column index of vertical line
	*      i is the index of the row of letter.
	*/
	string convert2(string s, int nRows) {
		if (nRows <= 1) {
			return s;
		}
		
		string result("");
		int dValue = 2 * nRows - 2;
		for (int i = 0; i < nRows; i++) {
			for (int j = i; j < s.length(); j += dValue) {
				result += s[j];
				int diagonal = j + dValue - 2 * i;
				if (i != 0 && i != nRows - 1 && diagonal < s.length()) {
					result += s[diagonal];
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	string ss = "PAYPALISHIRING";
	
	cout << "Solution 1:" << s->convert1(ss, 3) << endl;
	cout << "Solution 1:" << s->convert1(ss, 4) << endl;
	cout << "Solution 1:" << s->convert1(ss, 5) << endl;
	
	cout << "Solution 1:" << s->convert2(ss, 3) << endl;
	cout << "Solution 1:" << s->convert2(ss, 4) << endl;
	cout << "Solution 1:" << s->convert2(ss, 5) << endl;
	
	delete s;
	return 0;
}
