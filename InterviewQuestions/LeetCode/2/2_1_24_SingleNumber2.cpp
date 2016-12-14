/*******************************************************
* Given an array of integers, every element appears three times except for one.
* Find that single one.
* Note: Your algorithm should have a linear runtime complexity. Could you
* implement it without using extra memory?
*******************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int singleNumber(vector<int> &nums) {
		const int len = sizeof(int) * 8;
		vector<int> count(len, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < len; j++) {
				count[j] += ((nums[i] >> j) & 1);
				count[j] %= 3;
			}
		}

		int result = 0;
		for (int i = 0; i < len; i++) {
			result += (count[i] << i);
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 3, 3, 3, 4, 4, 4, 5 };
	
	cout << "Solution: " << s->singleNumber(nums) << endl;
	
	delete s;
	return 0;
}