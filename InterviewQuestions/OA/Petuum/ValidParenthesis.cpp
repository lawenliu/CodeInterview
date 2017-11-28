
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (left.find(s[i]) != string::npos) {
                st.push(s[i]);
            } else if (!st.empty() && st.top() == left[right.find(s[i])]) {
                st.pop();
            } else {
							cout << "Test" << endl;
                return false;
            }
        }
        
        return st.empty();
    }
};

int main(void) {
	Solution *s = new Solution();
	
	string ss = "()";
	
	cout << s->isValid(ss) << endl;
	
	delete s;
	return 0;
}