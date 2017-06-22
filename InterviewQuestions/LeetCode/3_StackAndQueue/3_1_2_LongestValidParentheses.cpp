/*******************************************
* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
* parentheses substring.
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*******************************************/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(n) */
	int longestValidParentheses(const string &s) {
		int maxLen = 0;
		int lastIndex = -1; // the first position is 0
		stack<int> stk;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			} else {
				if (stk.empty()) {
					lastIndex = i;
				} else {
					stk.pop();
					if (stk.empty()) {
						maxLen = i - lastIndex;
					} else {
						maxLen = max(maxLen, i - stk.top());
					}
				}
			}
		}
		
		return maxLen;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "(()";
	string s2 = ")()())";
	
	cout << "Solution 1: " << s->longestValidParentheses(s1) << endl;
	cout << "Solution 1: " << s->longestValidParentheses(s2) << endl;
	
	delete s;
	return 0;
}