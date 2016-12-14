/***********************************
* Determin whether an integer is a palindrome. Do this without extra space.
* Some hints:
* Could negative integers be palindromes? (ie, -1)
* If you are thinking of converting the integer to string, note the restriction of
* using extra space.
* You could also try reversing an integer. However, if you have solved the problem
* "Reverse Integer", you know that the reversed integer might overflow. How would
* you handle such case?
* There is a more generic way of solving this problem.
***********************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		
		int s = 1;
		int t = x;
		while (t >= 10) {
			s *= 10;
			t /= 10;
		}
		
		t = x;
		while (t > 0) {
			int q = t / s;
			int r = t % 10;
			if (q != r) {
				return false;
			}
			
			t %= s;
			t /= 10;
			s /= 100;
		}
		
		return true;
	}
};

int main(void) {
	Solution* s = new Solution();
	int x1 = -122;
	int x2 = 123321;
	int x3 = 1234321;
	int x4 = 1;
	int x5 = 1234566;
	
	cout << "Solution 1: " << s->isPalindrome(x1) << endl;
	cout << "Solution 1: " << s->isPalindrome(x2) << endl;
	cout << "Solution 1: " << s->isPalindrome(x3) << endl;
	cout << "Solution 1: " << s->isPalindrome(x4) << endl;
	cout << "Solution 1: " << s->isPalindrome(x5) << endl;
	
	delete s;
	return 0;
}