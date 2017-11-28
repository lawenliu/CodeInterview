/***************************************************
* Given a string array representing a throw ball blocks, each string is either a * * number, +, Z, X. Calculate total. If number, just add to total. If +, add last 2 * scores to total.
* If Z, remove last score from total. If X, double last score and add to toal.
* Use 0 for any missing last score.
***************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
	int getBaseballScore(vector<string> input) {
		stack<int> s;
		int res = 0;
		for (string op : input) {
			if (op[0] == 'z' && !s.empty()) {
				s.pop();
			} else if (op[0] == 'x' && !s.empty()) {
				int a = s.top();
				s.push(a * 2);
			} else if (op[0] == '+') {
				int a = 0;
				int b = 0;
				int c = 0;
				bool getB = false;
				bool getA = false;
				if (!s.empty()) {
					b = s.top();
					s.pop();
					getB = true;
				}
				
				if (!s.empty()) {
					a = s.top();
					s.pop();
					bool getA = true;
				}
				
				c = a + b;
				if (getA) {
					s.push(a);
				}
				
				if (getB) {
					s.push(b);
				}
				
				s.push(c);
			} else {
				s.push(stoi(op));
			}
		}
		
		while (!s.empty()) {
			res += s.top();
			s.pop();
		}
		
		return res;
	}
};

int main(void) {
	Solution *s = new Solution();
	
	
	
	delete s;
	return 0;
}
