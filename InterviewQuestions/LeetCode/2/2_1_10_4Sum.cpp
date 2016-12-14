/*********************************************
* Given an array S of n integers, are there elements a, b, c, and d in S
* such that a + b + c = target? Find all unique quadruplets in the array
* which gives the sum of target.
* Note:
* 1. Elements in a quadruplets (a, b, c, d) must be in non-descending
*    order. (ie, a <= b <= c <= d)
* 2. The solution set must not contain duplicate quadruplets.
* For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
* A solution set is£º
* (-1,  0, 0, 1)
* (-2, -1, 1, 2)
* (-2,  0, 0, 2)
*********************************************/
#include <iostream>
#include <vector>
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
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> result;
		if (nums.size() < 3) {
			return result;
		}
		
		mergeSort(nums, 0, nums.size() - 1);
		const int target = 0;
		
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			
			for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j-1]) {
					continue;
				}
				
				int k = j + 1;
				int l = nums.size() - 1;
				while (k < l) {
					if (nums[i] + nums[j] + nums[k] + nums[l] < target) {
						k++;
						while (nums[k] == nums[k-1] && k < l) {
							k++;
						}
					} else if (nums[i] + nums[j] + + nums[k] + nums[l] > target) {
						l--;
						while (nums[l] == nums[l+1] && k < l) {
							l--;
						}
					} else {
						result.push_back({ nums[i], nums[j], nums[k], nums[l] });
						k++;
						l--;
						while (nums[k] == nums[k-1] && k < l) {
							k--;
						}
						
						while (nums[l] == nums[l+1] && k < l) {
							l--;
						}
					}
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> result = s->threeSum(nums);
	
	cout << "Solution:" << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}