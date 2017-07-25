/****************************************************************
* Given a sorted array and a target value, return the index if the
* target is found. If not, return the index where it would be if
* it were inserted in order.
* You may assume no duplicates in the array.
* Here are few examples.
*  [1, 3, 5, 6], 5 -> 2
*  [1, 3, 5, 6], 2 -> 1
*  [1, 3, 5, 6], 7 -> 4
*  [1, 3, 5, 6], 0 -> 0
****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int searchInsert1(vector<int> &nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= target) {
				return i;
			}
		}
		
		return nums.size();
	}
	
	/* Time: O(log n), Space: O(1) */
	int searchInsert2(vector<int> &nums, int target) {
		int left = 0;
		int right = nums.size(); // the position should go the backend of this array
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		
		return right;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> array = { 1, 3, 5, 6 };
	
	cout << "Solution 1: " << s->searchInsert1(array, 5) << endl;
	cout << "Solution 1: " << s->searchInsert1(array, 2) << endl;
	cout << "Solution 1: " << s->searchInsert1(array, 7) << endl;
	cout << "Solution 1: " << s->searchInsert1(array, 0) << endl;
	
	cout << "Solution 2: " << s->searchInsert2(array, 5) << endl;
	cout << "Solution 2: " << s->searchInsert2(array, 2) << endl;
	cout << "Solution 2: " << s->searchInsert2(array, 7) << endl;
	cout << "Solution 2: " << s->searchInsert2(array, 0) << endl;
	
	delete s;
	return 0;
}