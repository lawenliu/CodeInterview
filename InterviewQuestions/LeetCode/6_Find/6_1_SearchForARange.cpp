/***********************************************
* Given a sorted array of integers, find the starting and ending position of
* a given target value.
* Your algorithm's runtime complexity must be in the order of O(logn).
* If the target is not found in the array, return [-1, -1].
* For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
***********************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(logn), Space: O(1) */
	vector<int> searchRange(vector<int> &nums, int target) {
		int lower = lowerBound(nums, target);
		int upper = upperBound(nums, target);
		cout << lower << " " << upper << endl;
		
		if (lower >= nums.size() || upper <= -1 || nums[lower] != target || nums[upper] != target) {
			return vector<int> { -1, -1 };
		} else {
			return vector<int> { lower, upper };
		}
	}
	
	int lowerBound(vector<int> nums, int target) {
		int first = 0;
		int last = nums.size() - 1;
		
		while (first < last) {
			int mid = (first + last) / 2;
			if (nums[mid] < target) {
				first = mid + 1;
			} else {
				last = mid;
			}
		}
		
		return first;
	}
	
	int upperBound(vector<int> nums, int target) {
		int first = 0;
		int last = nums.size() - 1;
		
		while (first < last) {
			int mid = (first + last) / 2 + 1; // Take care of this
			if (nums[mid] > target) {
				last = mid - 1;
			} else {
				first = mid;
			}
		}
		
		return first;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums1 = { 5, 7, 7, 8, 8, 10 };
	vector<int> nums2 = { 3, 2, 1, 5 };
	
	vector<int> result = s->searchRange(nums1, 8);
	cout << "Solution 1: [" << result[0] << ", " << result[1] << "]" << endl;
	result = s->searchRange(nums2, 8);
	cout << "Solution 1: [" << result[0] << ", " << result[1] << "]" << endl;
	
	delete s;
	return 0;
}