/****************************************************************
* Implement next permutation, which rearrages numbers into the
* lexicographically next greater permutation of numbers.
* If such arrangement is not possible, it must rearrage it as
* the lowest possible order (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.
* Here are some examples. Inputs are in the left-hand column and
* its corresponding outputs are in the right hand column.
*  1, 2, 3 -> 1, 3, 2
*  3, 2, 1 -> 1, 2, 3
*  1, 1, 5 -> 1, 5, 1
****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	void nextPermutation1(vector<int> &nums) {
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
		for (; change >= 0; change--) {
			if (nums[pivot] < nums[change]) {
				break;
			}
		}
		
		swap(nums[pivot], nums[change]);
		reverse(nums.begin() + pivot + 1, nums.end());
	}
	
	/* Time: O(n), Space: O(1) */
	/* Simple one */
	void nextPermutation(vector<int> &nums) {
		if (nums.size() == 0) {
			return;
		}
		
		const int n = nums.size();
		int pivot = -1;
		for (pivot = n - 2; pivot >= 0; pivot--) {
			if (nums[pivot] < nums[pivot+1]) {
				for (int change = n - 1; change >= 0; change--) {
					if (nums[pivot] < nums[change]) {
						swap(nums[pivot], nums[change]);
						break;
					}
				}
				
				break;
			}
		}
		
		reverse(nums.begin() + pivot + 1, nums.end());
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> nums1 = { 1, 2, 3 };
	s->nextPermutation(nums1);
	cout << "Result:" << endl;
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	
	cout << endl;
	
	vector<int> nums2 = { 3, 2, 1 };
	s->nextPermutation(nums2);
	cout << "Result:" << endl;
	for (int i = 0; i < nums2.size(); i++) {
		cout << nums2[i] << " ";
	}
	
	cout << endl;
	
	vector<int> nums3 = { 1, 1, 5 };
	s->nextPermutation(nums3);
	cout << "Result:" << endl;
	for (int i = 0; i < nums3.size(); i++) {
		cout << nums3[i] << " ";
	}

	cout << endl;
	vector<int> nums4 = { 6, 8, 7, 4, 3, 2 };
	s->nextPermutation(nums4);
	cout << "Result:" << endl;
	for (int i = 0; i < nums4.size(); i++) {
		cout << nums4[i] << " ";
	}
	
	delete s;
	return 0;
}
