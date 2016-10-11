/********************************
* Reverse digits of an integer.
* Example1: x = 123, return 321
* Example2: x - 123, return -321
* Have you thought about this?
* Here are some good questions to ask before coding. Bonus for you if you have already thought
* through this!
* If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* Did you notice that the reversed integer might overflow? Assume the input is a 32-bit
* integer, then the reverse of 1000000003 overflows. How should you handle such cases?
* Throw an exception? Good, but what if throwing an exception is not an option? You would then
* have to re-design the function (ie, add an extra parameter)
********************************/
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
		
		if ((f > 0 && result > 2147483647) || (f < 0 && result > 2147483648)) {
			return 0;
		}
		
		return result * f;
	}
};

int main(void) {
	Solution* s = new Solution();
	int x1 = 123;
	int x2 = -123;
	int x3 = 1000000003;
	
	cout << "Solution 1: " << s->reverse(x1) << endl;
	cout << "Solution 1: " << s->reverse(x2) << endl;
	cout << "Solution 1: " << s->reverse(x3) << endl;
	
	delete s;
	return 0;
}