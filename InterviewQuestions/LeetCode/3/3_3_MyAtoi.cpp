/**********************************
* Implement atoi to convert a string to an integer.
* Hint: Carefully consider all possible input cases. If you want a challenge, please
* do not see below and ask yourself what are the possible input cases.
* Notes: It is intended for this problem to be specified vaguely (ie, no given input
* specs). You are responsible to gather all the input requirements up front.
* Requirements for atoi:
* The function first discards as many whitespace characters as neccessary until the
* first non-whitespace character is found. Then, starting from this character, takes
* an optional initial plus or minus sign followed by as many numerical digits as possible,
* and interprets them as a numerical value.
* The string can contain additional characters after those that form the inegral number,
* which are ignored and have no effect on the behavior of this function.
* If the first sequence of non-whitespace characters in str is not a valid integral number,
* or if no such sequence exists because either str is empty or it contains only whitespace
* characters, no conversion is performed.
* If no valid conversion could be performed, a zero value is returned. If the correct value
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
* is returned.
**********************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int myAtoi(const string &str) {
		int num = 0;
		int sign = 1;
		int i = 0;
		while (i < str.length() && str[i] == ' ') {
			i++;
		}
		
		if (str[i] == '+') {
			sign = 1;
			i++;
		} else if (str[i] == '-') {
			sign = -1;
			i++;
		}
		
		for (; i < str.length(); i++) {
			if (str[i] < '0' || str[i] > '9') {
				break;
			}
			
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
				return sign == -1 ? INT_MIN : INT_MAX;
			}
			
			num = num * 10 + str[i] - '0';
		}
		
		return num * sign;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "-3924x8fc";
	string s2 = "+413";
	string s3 = "++c";
	string s4 = "++1";
	string s5 = "2147483648";
	string s6 = "+2147483647";
	string s7 = "-2147483648";
	string s8 = "-2147483647";
	
	cout << "Solution 1: " << s->myAtoi(s1) << endl;
	cout << "Solution 1: " << s->myAtoi(s2) << endl;
	cout << "Solution 1: " << s->myAtoi(s3) << endl;
	cout << "Solution 1: " << s->myAtoi(s4) << endl;
	cout << "Solution 1: " << s->myAtoi(s5) << endl;
	cout << "Solution 1: " << s->myAtoi(s6) << endl;
	cout << "Solution 1: " << s->myAtoi(s7) << endl;
	cout << "Solution 1: " << s->myAtoi(s8) << endl;
	
	delete s;
}