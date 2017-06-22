/**************************************************
* Given an array S of n integers, find three integers in S such that
* the sum is closest to a given numer, target. Return the sum of the
* three integers. You may assume that each input would have exactly
* one solution.
* For example, given array S = {-1, 2, 1, -4}, and target = 1.
* The sum that is closest to the target is 2. {-1 + 2 + 1 = 2).
**************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	void mergeSort(vector<int> &nums, int first, int last) {
		if (first == last) {
			return;
		}
		
		int mid = (first + last) / 2;
		mergeSort(nums, first, mid);
		mergeSort(nums, mid + 1, last);
		merge(nums, first, mid, last);
	}
	
	void merge(vector<int> &nums, int first, int mid, int last) {
		vector<int> tmp;
		int i = first;
		int j = mid + 1;
		while (i <= mid && j <= last) {
			if (nums[i] < nums[j]) {
				tmp.push_back(nums[i]);
				i++;
			} else {
				tmp.push_back(nums[j]);
				j++;
			}
		}
		
		while (i <= mid) {
			tmp.push_back(nums[i]);
			i++;
		}
		
		while (j <= last) {
			tmp.push_back(nums[j]);
			j++;
		}
		
		for (int i = 0; i < tmp.size(); i++) {
			nums[first + i] = tmp[i];
		}
	}
public:
	/* Time: O(n^2), Space: O(1) */
	int threeSumClosest(vector<int> &nums, int target) {
		int result = 0;
		int minGap = INT_MAX;
		mergeSort(nums, 0, nums.size() - 1);
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				int gap = abs(sum - target);
				
				if (gap < minGap) {
					minGap = gap;
					result = sum;
				}
				
				if (sum < target) {
					j++;
				} else {
					k--;
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { -1, 2, 1, -4 };
	cout << "Solution: " << s->threeSumClosest(nums, 1) << endl;
	
	delete s;
	return 0;
}