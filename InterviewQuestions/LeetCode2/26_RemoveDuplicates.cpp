/************************************************************************
* Given a sorted array, remove the duplicates in place such that each element
* appear only once and return the new length.
* Do not allocate extra space for another array, you must do this in place
* with constant memory.
* For example,
*  Given input array A = [1, 1, 2],
* You function should return length = 2, and A is now [1, 2].
************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int removeDuplicates(vector<int> &nums) {
		if (nums.size() < 2) {
			return nums.size();
		}
		
		int start = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[start] != nums[i]) {
				start++;
				nums[start] = nums[i];
			}
		}
		
		// We don't need remove the rest numbers
		for (int i = nums.size() - 1; i > start; i--) {
			nums.pop_back();
		}
		
		return start + 1;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> nums = { 1, 1, 2, 2, 2, 3 };
	cout << "Solution 1: " << s->removeDuplicates(nums) << endl;
	
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << "; ";
	}
	
	delete s;
	return 0;
}