/************************************************
* Given a sorted array and a target value, return the index
* if the target is found. If not, return the index where it
* would be if it were inserted in order.
* You may assume no duplicates in the array.
* Here are few examples.
* [1, 3, 5, 6], 5 -> 2
* [1, 3, 5, 6], 2 -> 1
* [1, 3, 5, 6], 7 -> 4
* [1, 3, 5, 6], 0 -> 0
************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(logn), Space: O(1) */
	int searchInsert(vector<int> &nums, int target) {
		int first = 0;
		int last = nums.size(); // Take care this
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
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 1, 3, 5, 6 };
	
	cout << "Solution 1: " << s->searchInsert(nums, 5) << endl;
	cout << "Solution 1: " << s->searchInsert(nums, 2) << endl;
	cout << "Solution 1: " << s->searchInsert(nums, 7) << endl;
	cout << "Solution 1: " << s->searchInsert(nums, 0) << endl;
	
	delete s;
	return 0;
}