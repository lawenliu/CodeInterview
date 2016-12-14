/*******************************************************
* Given an array of integers, every element appear twice except for one. Find that single one.
* Note: Your algorithm should have a linear runtime complexity. Could you implement it without
* using extra memory?
*******************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int singleNumber(vector<int> &nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); i++) {
			result ^= nums[i];
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 3, 2, 3, 4, 4, 2, 5 };
	
	cout << "Solution: " << s->singleNumber(nums);
	
	delete s;
	return 0;
}