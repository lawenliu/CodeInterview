/******************************************************************************
* Given n pairs of parentheses, write a function to generate all combination of
* well-formed parentheses.
* For example, given n = 3, a solution set is:
* "((()))", "(()())", "(())()", "()(())", "()()()"
******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void generateParentheses1Aux(int n, string &path, vector<string> &result, int l, int r) {
		if (l == n) {
			string s(path);
			s.append(l-r, ')');
			result.push_back(s);
			return;
		}
		
		path.push_back('(');
		generateParentheses1Aux(n, path, result, l + 1, r);
		path.pop_back();
		
		if (l > r) {
			path.push_back(')');
			generateParentheses1Aux(n, path, result, l, r + 1);
			path.pop_back();
		}
	}
public:
	/* Time: O(n^2), Space: O(n) */
	vector<string> generateParentheses1(int n) {
		vector<string> result;
		string  path;
		generateParentheses1Aux(n, path, result, 0, 0);
		return result;
	}
	
	/* Time: O(n^2), Space: O(1) */
	vector<string> generateParentheses2(int n) {
		if (n == 0) {
			return vector<string> (1, "");
		}
		
		if (n == 1) {
			return vector<string> (1, "()");
		}
		
		vector<string> result;
		for (int i = 0; i < n; i++) {
			for (string inner : generateParentheses2(i)) {
				for (string outer : generateParentheses2(n - 1 - i)) {
					string path = "(" + inner + ")" + outer;
					result.push_back(path);
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	
	vector<string> result = s->generateParentheses1(3);
	cout << "Solution 1:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	result = s->generateParentheses2(3);
	cout << "Solution 2:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	delete s;
	return 0;
}
