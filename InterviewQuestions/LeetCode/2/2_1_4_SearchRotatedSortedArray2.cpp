/***********************************
* Follow up for "Search in Rotated Sorted Array": What if duplicates are allowed?
* Would this affect the run-time complexity? How and why?
* Write a function to determine if a given target is in the array.
***********************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(logn), Space: O(1) */
	bool search(const vector<int> &nums, int target) {
		int first = 0;
		int last = nums.size() - 1;
		while (first <= last) {
			int middle = (first + last) / 2;
			if (nums[middle] == target) {
				return true;
			} else if (nums[first] < nums[middle]) {
				if (nums[first] <= target && target < nums[middle]) {
					last = middle - 1;
				} else {
					first = middle + 1;
				}
			} else if (nums[first] > nums[middle]) {
				if (nums[middle] < target && target < nums[last]) {
					first = middle + 1;
				} else {
					last = middle - 1;
				}
			} else {
				first++;
			}
		}
		
		return false;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(10);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	
	cout << "Solution 1: " << s->search(nums, 8) << endl;
	cout << "Solution 1: " << s->search(nums, 7) << endl;
	
	delete s;
	return 0;
}