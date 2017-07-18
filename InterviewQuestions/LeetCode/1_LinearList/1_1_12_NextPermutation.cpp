/************************************************************
* Implement next permutation, which rearranges numbers into the lexicographically
* next greater permutation of numbers.
* If such arrangement is not possible, it must rearrange it as the lowest possible
* order (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.
* Here are some examples. Inputs are in the left-hand column and it corresponding
* outputs are in the right-hand column.
*  1, 2, 3 -> 1, 3, 2
*  3, 2, 1 -> 1, 2, 3
*  1, 1, 5 -> 1, 5, 1
************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	void nextPermutation(vector<int> &nums) {
		if (nums.size() == 0) {
			return;
		}
		const int n = nums.size();
		int pivot = n - 2;
		for (; pivot >= 0; pivot--) {
			if (nums[pivot] < nums[pivot+1]) {
				break;
			}
		}
		
		if (pivot < 0) {
			reverse(nums.begin(), nums.end());
			return;
		}
		
		int change = n - 1;
		for(; change >= 0; change--) {
			if (nums[pivot] < nums[change]) {
				break;
			}
		}
		
		swap(nums[pivot], nums[change]);
		for (int i = pivot + 1, j = n - 1; i < (n + pivot + 1) / 2; i++, j--) {
			swap(nums[i], nums[j]);
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 6, 8, 7, 4, 3, 2 };
	
	s->nextPermutation(nums);
	cout << "Result:" << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	
	delete s;
	return 0;
}