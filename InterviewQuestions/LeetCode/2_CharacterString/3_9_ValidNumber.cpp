/********************************************
* Validate if a given string is numeric.
* Some example:
* "0" => true
* "0.1" => true
* "abc" => false
* "1 a" => false
* "2e10" => true
* Note: It is intended for the problem statement to be ambiguous.
* You should gather all requirements up front before implementing one.
********************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	bool isNumber(const string &s) {
		enum InputType {
			INVALID,
			SPACE,
			SIGN,
			DIGIT,
			DOT,
			EXPONENT
		};
		
		int transitionTable[][6] = {
			-1, 0, 3, 1, 2, -1,
			-1, 8, -1, 1, 4, 5,
			-1, -1, -1, 4, -1, -1,
			-1, -1, -1, 1, 2, -1,
			-1, 8, -1, 4, -1, 5,
			-1, -1, 6, 7, -1, -1,
			-1, -1, -1, 7, -1, -1,
			-1, 8, -1, 7, -1, -1,
			-1, 8, -1, -1, -1, -1
		};
		
		int state = 0;
		for (int i = 0; i < s.length(); i++) {
			InputType inputType = INVALID;
			if (s[i] == ' ') {
				inputType = SPACE;
			} else if (s[i] == '+' || s[i] == '-') {
				inputType = SIGN;
			} else if (s[i] >= '0' && s[i] <= '9') {
				inputType = DIGIT;
			} else if (s[i] == '.') {
				inputType = DOT;
			} else if (s[i] == 'e' || s[i] == 'E') {
				inputType = EXPONENT;
			}
			
			state = transitionTable[state][inputType];
			
			if (state == -1) {
				return false;
			}
		}
		
		return state = 1 || state == 4 || state == 7 || state == 8;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "0";
	string s2 = "0.1";
	string s3 = "abc";
	string s4 = "1 a";
	string s5 = "2e10";
	
	cout << "Solution 1: " << s->isNumber(s1) << endl;
	cout << "Solution 1: " << s->isNumber(s2) << endl;
	cout << "Solution 1: " << s->isNumber(s3) << endl;
	cout << "Solution 1: " << s->isNumber(s4) << endl;
	cout << "Solution 1: " << s->isNumber(s5) << endl;
	
	
	delete s;
	return 0;
}
