/*****************************************************************
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* (i.e. 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* You are given a target value to search. If found in the array return
* its index, otherwise return -1.
* You may assume no duplicate exists in the array.
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int search2Aux(const vector<int> &nums, int target, int first, int last) {
		if (first <= last) {
			int middle = (first + last) / 2;
			if (nums[middle] == target) {
				return middle;
			} else if (nums[first] <= nums[middle]) {
				if (nums[first] <= target && target < nums[middle]) {
					return search2Aux(nums, target, first, middle - 1);
				} else {
					return search2Aux(nums, target, middle + 1, last);
				}
			} else {
				if (nums[middle] < target && target <= nums[last]) {
					return search2Aux(nums, target, middle + 1, last);
				} else {
					return search2Aux(nums, target, first, middle - 1);
				}
			}
		} else {
			return -1;
		}
	}
public:
	/* Tim: O(logn), Space: O(1) */
	int search1(const vector<int> &nums, int target) {
		int first = 0;
		int last = nums.size() - 1;
		while (first <= last) {
			int middle = (first + last) / 2;
			if (nums[middle] == target) {
				return middle;
			} else if (nums[first] <= nums[middle]) {
				if (nums[first] <= target && target < nums[middle]) {
					last = middle - 1;
				} else {
					first = middle + 1;
				}
			} else {
				if (nums[middle] < target && target <= nums[last]) {
					first = middle + 1;
				} else {
					last = middle - 1;
				}
			}
		}
		
		return -1;
	}
	
	/* Time: O(logn), Space: O(1) */
	int search2(const vector<int> &nums, int target) {
		return search2Aux(nums, target, 0, nums.size() - 1);
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> nums = { 7, 9, 10, 0, 1, 2, 3, 5 };
	cout << "Solution 1: " << s->search1(nums, 6) << endl;
	cout << "Solution 1: " << s->search1(nums, 4) << endl;
	cout << "Solution 1: " << s->search1(nums, 8) << endl;
	cout << "Solution 1: " << s->search1(nums, 9) << endl;
	cout << "Solution 1: " << s->search1(nums, 3) << endl;
	
	cout << "Solution 2: " << s->search2(nums, 6) << endl;
	cout << "Solution 2: " << s->search2(nums, 4) << endl;
	cout << "Solution 2: " << s->search2(nums, 8) << endl;
	cout << "Solution 2: " << s->search2(nums, 9) << endl;
	cout << "Solution 2: " << s->search2(nums, 3) << endl;
	
	delete s;
	return 0;
}