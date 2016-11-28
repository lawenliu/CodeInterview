/*************************************
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
* Some examples:
* ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
* ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*************************************/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
	bool isOperator(const string &str) {
		return str.size() == 1 && string("+-*/").find(str) != string::npos;
	}
public:
	/* Time: O(n), Space: O(lgn) */
	int evalRPN1(vector<string> &tokens) {
		int x, y;
		string token = tokens.back();
		tokens.pop_back();
		
		if (isOperator(token)) {
			y = evalRPN1(tokens);
			x = evalRPN1(tokens);
			switch (token[0]) {
				case '+':
					x += y;
					break;
				case '-':
					x -= y;
					break;
				case '*':
					x *= y;
					break;
				case '/':
					x /= y;
					break;
				default:
					// Throw exception here;
					break;
			}
		} else {
			size_t i;
			x = stoi(token, &i);
		}
		
		return x;
	}
	
	/* Time: O(n), Space: O(lgn) */
	int evalRPN2(vector<string> &tokens) {
		stack<int> stk;
		for (int i = 0; i < tokens.size(); i++) {
			if (!isOperator(tokens[i])) {
				stk.push(stoi(tokens[i]));
			} else {
				int y = stk.top();
				stk.pop();
				int x = stk.top();
				stk.pop();
				switch (tokens[i][0]) {
					case '+':
					x += y;
					break;
					case '-':
						x -= y;
						break;
					case '*':
						x *= y;
						break;
					case '/':
						x /= y;
						break;
					default:
						// Throw exception here;
						break;
				}
				
				stk.push(x);
			}
		}
		
		return stk.top();
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<string> tokens1;
	tokens1.push_back("2");
	tokens1.push_back("1");
	tokens1.push_back("+");
	tokens1.push_back("3");
	tokens1.push_back("*");
	
	vector<string> tokens2;
	tokens2.push_back("4");
	tokens2.push_back("13");
	tokens2.push_back("5");
	tokens2.push_back("/");
	tokens2.push_back("+");
	
	cout << "Solution 2: " << s->evalRPN2(tokens1) << endl;
	cout << "Solution 2: " << s->evalRPN2(tokens2) << endl;
	cout << "Solution 1: " << s->evalRPN1(tokens1) << endl;
	cout << "Solution 1: " << s->evalRPN1(tokens2) << endl;
	
	delete s;
	return 0;
}