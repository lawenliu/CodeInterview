/******************************
* Find the contiguous subarray within array (containing at least one number) which has the 
* largest sum. For example, given the array [-2, 1, -3, 4, -1, 2, 1, -5, 4],
* the contiguous subarray [4, -1, 2, 1] has the largest sum = 6.
******************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(1) */
	int maxSubarray1(vector<int> & nums) {
		int maxSubarray = INT_MIN;
		int subSum = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			subSum = 0;
			for (int j = i; j < nums.size(); j++) {
				subSum += nums[j];
				maxSubarray = max(maxSubarray, subSum);
			}
		}
		
		return maxSubarray;
	}
	
	/* Time: O(n), Space: O(1). f[i] = max(f[i - 1] + N[i], N[i])
	   f[i] is the maximum sum from 0 to i */
	int maxSubarray2(vector<int> &nums) {
		int maxSubarray = INT_MIN;
		int f = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			f = max(f + nums[i], nums[i]);
			maxSubarray = max(maxSubarray, f);
		}
		
		return maxSubarray;
	}
	
	/* Time: O(n), Space: O(n) */
	int maxSubarray3(vector<int> &nums) {
		int maxSubarray = INT_MIN;
		int curMin = INT_MIN;
		int* subSum = new int[nums.size() + 1];
		
		subSum[0] = 0;
		curMin = subSum[0];
		for (int i = 1; i <= nums.size(); i++) {
			subSum[i] = subSum[i - 1] + nums[i - 1];
		}
		
		for (int i = 1; i <= nums.size(); i++) {
			maxSubarray = max(maxSubarray, subSum[i] - curMin);
			curMin = min(curMin, subSum[i]);
		}
		
		return maxSubarray;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	
	cout << "Solution 1 :" << s->maxSubarray1(nums) << endl;
	cout << "Solution 1 :" << s->maxSubarray2(nums) << endl;
	cout << "Solution 1 :" << s->maxSubarray3(nums) << endl;
	
	delete s;
	return 0;
}