/***************************************************
* Implement wildcard pattern matching with support for '?' and '*'.
* '?' matches any single character.
* '*' matches any sequence of characters (including the empty sequence).
* The matching should cover the entire input string (not partial).
* The function prototype should be:
*   bool isMatch(const char *s, const char *p)
* Some examples:
* isMatch("aa", "a") -> false
* isMatch("aa", "aa") -> true
* isMatch("aaa", "aa") -> false
* isMatch("aa", "*") -> true
* isMatch("aa", "a*") -> true
* isMatch("ab", "?*") -> true
* isMatch("aab", "c*a*b") -> false
***************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n! * m!), Space: O(1) */
	bool isMatch1(const char *s, const char *p) {
		if (*s == '\0' || *p == '\0') {
			return *s == *p;
		} else if (*s == *p || *p == '?') {
			return isMatch1(s + 1, p + 1);
		} else if (*p == '*') {
			while (*p == '*') {
				p++;
			}
			
			if (*p == '\0') {
				return true;
			}
			
			while (*s != '\0' && !isMatch1(s, p)) {
				s++;
			}
			
			return *s != '\0';
		} else {
			return false;
		}
	}
	
	/* Time: O(n*m), Space: O(1) */
	bool isMatch2(const char *s, const char *p) {
		bool isStar = false;
		const char *str, *ptr;
		for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
			switch (*ptr) {
				case '?':
					break;
				case '*':
					isStar = true;
					s = str, p = ptr;
					while (*p == '*') {
						p++;
					}
					
					if (*p == '\0') {
						return true;
					}
					
					str = s - 1;
					ptr = p - 1;
					break;
				default:
					if (*str != *ptr) {
						if (!isStar) {
							return false;
						}
						
						s++;
						str = s - 1;
						ptr = p - 1;
					}
			}
		}
		
		while (*ptr == '*') {
			ptr++;
		}
			
		return *ptr == '\0';
	}
};

int main(void) {
	Solution* s = new Solution();
	
	cout << "Solution 1: " << s->isMatch1("aa", "a") << endl;
	cout << "Solution 1: " << s->isMatch1("aa", "aa") << endl;
	cout << "Solution 1: " << s->isMatch1("aaa", "aa") << endl;
	cout << "Solution 1: " << s->isMatch1("aa", "a*") << endl;
	cout << "Solution 1: " << s->isMatch1("aa", "?*") << endl;
	cout << "Solution 1: " << s->isMatch1("ab", "?*") << endl;
	cout << "Solution 1: " << s->isMatch1("aab", "c*a*b") << endl;
	
	cout << "Solution 2: " << s->isMatch2("aa", "a") << endl;
	cout << "Solution 2: " << s->isMatch2("aa", "aa") << endl;
	cout << "Solution 2: " << s->isMatch2("aaa", "aa") << endl;
	cout << "Solution 2: " << s->isMatch2("aa", "a*") << endl;
	cout << "Solution 2: " << s->isMatch2("aa", "?*") << endl;
	cout << "Solution 2: " << s->isMatch2("ab", "?*") << endl;
	cout << "Solution 2: " << s->isMatch2("aab", "c*a*b") << endl;
	
	delete s;
	return 0;
}
