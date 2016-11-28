/************************************************
* Given a string containing just the characters '(', ')',
* '{', '}', '[' and ']', determine if the input string is valid.
* The brackets must close in the correct order. "()" and "()[]"
* are all valid but "(]" and "([)]" are not.
************************************************/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(n) */
	bool isValid(string const &s) {
		string left = "([{";
		string right = ")]}";
		stack<char> stk;
		
		for (int i = 0; i < s.length(); i++) {
			if (left.find(s[i]) != string::npos) {
				stk.push(s[i]);
			} else {
				if (stk.empty() || stk.top() != left[right.find(s[i])]) {
					return false;
				} else {
					stk.pop();
				}
			}
		}
		
		return stk.empty();
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "()";
	string s2 = "()[]";
	string s3 = "(]";
	string s4 = "([)]";
	
	cout << "Solution 1: " << s->isValid(s1) << endl;
	cout << "Solution 1: " << s->isValid(s2) << endl;
	cout << "Solution 1: " << s->isValid(s3) << endl;
	cout << "Solution 1: " << s->isValid(s4) << endl;
	
	delete s;
	return 0;
}