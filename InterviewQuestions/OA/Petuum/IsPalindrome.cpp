#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        
        int i = 0, j = s.size() - 1;
        while (i < j) {
            int a = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 32 : s[i];
            int b = s[j] >= 'a' && s[j] <= 'z' ? s[j] - 32 : s[j];
            if (!::isalnum(a)) {
                i++;
            } else if (!::isalnum(b)) {
                j--;
            } else if (a == b) {
                i++; j--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};

int main(void) {
	Solution *s = new Solution();
	string ss = "0P";
	
	cout << "Solution: " << s->isPalindrome(ss) << endl;
	
	delete s;
	return 0;
}