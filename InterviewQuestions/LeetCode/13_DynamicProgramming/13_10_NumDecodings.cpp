/*************************************
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.
* For example, given encodeed message "12", it could be decoded as "AB" (1 2) or "L" (12).
* The number of ways decoding "12" is 2.
*************************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: , Space: O(1) */
	int numDecodings1(const string &s) {
		if (s.empty() || s[0] == '0') {
			return 0;
		}
		
		if (s.size() == 1) {
			return 1;
		}
		
		int n = numDecodings1(s.substr(1, s.size() - 1));
		if (s.size() >= 2 && (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))) {
			if (s.size() == 2) {
				return n + 1;
			}
			
			n = n + numDecodings1(s.substr(2, s.size() - 2));
		}
		
		return n;
	}
	
	/* Time: O(n), Space: O(1) */
	int numDecodings2(const string &s) {
		if (s.empty() || s[0] == '0') {
			return 0;
		}
		
		int prev = 0;
		int cur = 1;
		for ( int i = 1; i <= s.size(); i++) {
			if (s[i-1] == '0') {
				cur = 0;
			}
			
			if (!(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
				prev = 0;
			}
			
			int temp = cur;
			cur = prev + cur;
			prev = temp;
		}
		
		return cur;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s0 = "12";
	string s1 = "0123";
	string s2 = "123456728";
	
	cout << "Solution 1: " << s->numDecodings1(s0) << endl;
	cout << "Solution 1: " << s->numDecodings1(s1) << endl;
	cout << "Solution 1: " << s->numDecodings1(s2) << endl;
	cout << "Solution 2: " << s->numDecodings2(s0) << endl;
	cout << "Solution 2: " << s->numDecodings2(s1) << endl;
	cout << "Solution 2: " << s->numDecodings2(s2) << endl;

	delete s;
	return 0;
}