/******************************************************
* Divide two integers without using multiplication, division
* and mod operator.
* If it is overflow, return MAX_INT.
******************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: O(log(n)), Space: O(1) */
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		
		// When dividen is INT_MIN, the -dividend will be overflow, so we use (long long)
		long long a = dividend >= 0 ? dividend : -(long long) dividend;
		long long b = divisor >= 0 ? divisor : -(long long) divisor;
		
		long long result = 0;
		while (a >= b) {
			long long c = b;
			for (int i = 0; a >= c; i++, c <<= 1) {
				a = a - c;
				result = result + (1 << i);
			}
		}
		
		return ((dividend ^ divisor) >> 31) ? (-result) : (result);
	}
	
	int 
};

int main(void) {
	Solution *s = new Solution();
	
	cout << "Solution 1: " << s->divide(1000, 11) << endl;
	cout << "Solution 1: " << s->divide(INT_MIN, -1) << endl;
	
	delete s;
	return 0;
}
