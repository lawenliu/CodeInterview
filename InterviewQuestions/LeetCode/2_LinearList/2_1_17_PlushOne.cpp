/************************************************************
* Given a number represented as an array of digits, plus one to the number.
************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--) {
			carry = (digits[i] + carry) / 10;
			digits[i] = (digits[i] + carry) % 10;			
		}
		
		if (carry > 0) {
			digits.insert(digits.begin(), carry);
		}
		
		return digits;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> digits1 = { 1, 1, 1 };
	vector<int> digits2 = { 9, 9, 9 };
	
	vector<int> result = s->plusOne(digits1);
	cout << "Result 1:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	
	result = s->plusOne(digits2);
	cout << endl << "Result 2:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	
	delete s;
	return 0;
}