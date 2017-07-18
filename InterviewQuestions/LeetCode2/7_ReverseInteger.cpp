/*************************************************************
* Reverse digits of an integer.
* Example1: x = 123, return 321
* Example2: x = -123, return -321

* Have you thought about this?
* Here are some good questions to ask before coding. Bonus
* points for you if you have already thought through this!
* If the integer's last digit is 0, what should the output be?
* ie, cases such as 10, 100.
* Did you notice that the reversed integer might overflow?
* Assume the input is a 32-bit integer, then the reverse of
* 1000000003 overflows. How should you handle such cases?
* For the purpose of this problem, assume that your function
* return 0 when the reserved integer overflows.
*************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int reverse(int x) {
		long long result = 0;
		long long f = x > 0 ? 1 : -1;
		long long temp = x * f;
		while (temp > 0) {
			result = result * 10 + temp % 10;
			temp = temp / 10;
		}
		
		/* Because the INT range is -2147483648 ~ 2147483647
		   So we don't need care about the result is 2147483648 or 2147483647,
			 we just need check whether result is bigger than 2147483647,
			 because the orignal one can't be 8463847412 or 7463847412. */
		if (result > INT_MAX) {
			return 0;
		}
		
		return result * f;
	}
};

int main(void) {
	Solution *s = new Solution();
	int x1 = 123;
	int x2 = -123;
	int x3 = 1000000003;
	
	cout << "Solution 1: " << s->reverse(x1) << endl;
	cout << "Solution 1: " << s->reverse(x2) << endl;
	cout << "Solution 1: " << s->reverse(x3) << endl;
	
	delete s;
	return 0;
}
