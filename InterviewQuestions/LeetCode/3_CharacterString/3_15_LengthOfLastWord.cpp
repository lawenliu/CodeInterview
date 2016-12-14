/***************************************************
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return
* the length of last word in the string.
* If the last word does not exist, return 0.
* Note: A word is defined as a character sequence consits of non-space characters only.
* For example, given s = "Hello world", return 5.
***************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int lengthOfLastWord1(const string &s) {
		int len = 0;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				len = 0;
			} else {
				len++;
			}
		}
		
		return len;
	}
	
	int lengthOfLastWord2(const string &s) {
		int len = 0;
		
		for (int i = s.length() - 1; i >= 0; i++) {
			if (s[i] == ' ') { //  && len > 0
				return len;
			}
			
			len++;
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "Hello World";
	string s2 = "Hello World ";
	string s3 = "Hello brother and sister";
	string s4 = " Hello brother and sister";
	string s5 = "Hello brother and sister ";
	
	cout << "Solution 1: " << s->lengthOfLastWord1(s1) << endl;
	cout << "Solution 1: " << s->lengthOfLastWord1(s2) << endl;
	cout << "Solution 1: " << s->lengthOfLastWord1(s3) << endl;
	cout << "Solution 1: " << s->lengthOfLastWord1(s4) << endl;
	cout << "Solution 1: " << s->lengthOfLastWord1(s5) << endl;
	cout << "Solution 2: " << s->lengthOfLastWord1(s1) << endl;
	cout << "Solution 2: " << s->lengthOfLastWord1(s2) << endl;
	cout << "Solution 2: " << s->lengthOfLastWord1(s3) << endl;
	cout << "Solution 2: " << s->lengthOfLastWord1(s4) << endl;
	cout << "Solution 2: " << s->lengthOfLastWord1(s5) << endl;
	
	delete s;
	return 0;
}