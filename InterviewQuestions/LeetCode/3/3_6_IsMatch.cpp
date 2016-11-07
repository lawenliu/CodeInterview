/************************************************
* Implement regular expression matching with support for '.' and '*'.
* '.' matches any single character. '*' matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* Some exaple:
* isMatch("aa", "a") -> flase
* isMatch("aa", "aa") -> true
* isMatch("aaa", "aa") -> false
* isMatch("aa", "a*") -> true
* isMatch("aa", ".*") -> true
* isMatch("ab", ".*") -> true
* isMatch("aab", "c*a*b") -> true
************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') { // End of the *p
			return *s == '\0';
		}
		
		if (*(p + 1) != '*') {
			if (*p == *s || (*p == '.' && *s != '\0')) {
				return isMatch(s + 1, p + 1);
			} else {
				return false;
			}
		} else {
			while (*p == *s || (*p == '.' && *s != '\0')) {
				if (isMatch(s, p + 2)) {
					return true;
				}
				
				s++;
			}
			
			return isMatch(s, p + 2);
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	
	cout << "Solution 1: " << s->isMatch("aa", "a") << endl;
	cout << "Solution 1: " << s->isMatch("aa", "aa") << endl;
	cout << "Solution 1: " << s->isMatch("aaa", "aa") << endl;
	cout << "Solution 1: " << s->isMatch("aa", "a*") << endl;
	cout << "Solution 1: " << s->isMatch("aa", ".*") << endl;
	cout << "Solution 1: " << s->isMatch("ab", ".*") << endl;
	cout << "Solution 1: " << s->isMatch("aab", "c*a*b") << endl;
	
	delete s;
	return 0;
}