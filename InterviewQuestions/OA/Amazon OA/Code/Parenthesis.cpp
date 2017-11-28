/**********************************************
* Check parenthesis
**********************************************/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	bool checkParenthesis(string parenthesis) {
		stack<char> s;
		for (char c : parenthesis) {
			if (c == '(') {
				s.push(c);
			} else if (!s.empty()) {
				s.pop();
			} else {
				return false;
			}
		}
		
		return s.empty();
	}
};

int main(void) {
	Solution *s = new Solution();
	string s0 = "";
	string s1 = "(((())))";
	string s2 = "()(())()";
	string s3 = "((())";
	string s4 = ")(())";
	string s5 = "(()))";
	
	cout << s0 << ":" << s->checkParenthesis(s0) << endl;
	cout << s1 << ":" << s->checkParenthesis(s1) << endl;
	cout << s2 << ":" << s->checkParenthesis(s2) << endl;
	cout << s3 << ":" << s->checkParenthesis(s3) << endl;
	cout << s4 << ":" << s->checkParenthesis(s4) << endl;
	cout << s5 << ":" << s->checkParenthesis(s5) << endl;
	
	delete s;
	return 0;
}