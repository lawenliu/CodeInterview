/******************************************************
* You are climbing a stair case. It takes n steps to reach to top.
* Each time you can either climb 1 or 2 steps. In how many distinct ways
* can you climb to the top?
******************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int climbingStairs1(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		
		return climbingStairs1(n - 1) + climbingStairs1(n - 2);
	}
	
	/* Time: O(n), Space: O(1) */
	int climbingStairs2(int n) {
		int prev  = 0;
		int cur = 1;
		for (int i = 1; i <= n; i++) {
			int tmp = cur;
			cur = cur + prev;
			prev = tmp;
		}
		
		return cur;
	}
	
	/* Time: O(1), Space: O(1) */
	/* an = (1/sqrt(5))*(((1+sqrt(5))/2)^n + ((1-sqrt(5))/2)^n) */
	int climbingStairs3(int n) {
		double r = sqrt(5);
		return floor((pow((1 + r) / 2, n + 1) + pow((1 - r) / 2 , n + 1)) / r + 0.5);
	}
};

int main(void) {
	Solution* s = new Solution();
	
	cout << "Solution 1: " << s->climbingStairs1(10) << endl;
	cout << "Solution 1: " << s->climbingStairs2(10) << endl;
	cout << "Solution 1: " << s->climbingStairs3(10) << endl;
	
	delete s;
	return 0;
}