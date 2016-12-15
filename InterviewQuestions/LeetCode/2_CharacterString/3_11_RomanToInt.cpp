/***********************************************
* Given a roman numeral, convert it to an integer.
* Input is guranteed to be within the range from 1 to 3999.
***********************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	int map(const char c) {
		switch (c) {
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}
public:
	int romanToInt(const string &s) {
		int result = 0;
		for (int i = 0; i < s.length(); i++) {
			if (i > 0 && map(s[i]) > map(s[i-1])) {
				result += (map(s[i]) - 2 * map(s[i-1]));
			} else {
				result += map(s[i]);
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "IVCLXMDDII";
	string s2 = "DDXI";
	
	cout << "Solution 1: " << s->romanToInt(s1) << endl;
	cout << "Solution 1: " << s->romanToInt(s2) << endl;	
	
	delete s;
	return 0;
}