/****************************************************
* Given two binary strings, return their sum (also a binary string).
* For example:
* a = "11"
* b = "1"
* Return "100"
****************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	string addBinary(string a, string b) {
		string result;
		int carry = 0;
		int i = 0, j = 0;
		while ( i < a.length() || j < b.length()) {
			const int first = i < a.length() ? a[i] - '0' : 0;
			const int second = j < b.length() ? b[j] - '0' : 0;
			const int val = (first + second + carry) % 2;
			carry = (first + second + carry) / 2;
			result.insert(result.begin(), val + '0');
			i++;
			j++;
		}
		
		if (carry != 0) {
			result.insert(result.begin(), carry + '0');
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	string a = "11";
	string b = "1";
	
	cout << "Solution 1: " << s->addBinary(a, b) << endl;
	
	delete s;
	return 0;
}
