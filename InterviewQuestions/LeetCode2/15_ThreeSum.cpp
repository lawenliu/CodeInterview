/**********************************************************************
* Given an array S of n Integers, are there elements a, b, c in S such
* that a + b + c = 0? Find all unique triplets in the array which gives
* the sum of zero.
* Note:
* 1. Elements in a triplet (a, b, c) must be in non-descending order.
*    (ie, a<=b<=c)
* 2. The solution set must not contain duplicate triplets.
* For example, given array S = { -1 0 1 2 -1 -4 }.
* A solution set is:
* (-1, 0, 1)
* (-1, -1, 2) 
**********************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	/* Time: O(n), Space: O(n) */
	void mergeSort(vector<int> &nums, int first, int last) {
		if (first < last) {
			int mid = (first + last) / 2;
			mergeSort(nums, first, mid);
			mergeSort(nums, mid + 1, last);
			merge(nums, first, mid, last);
		}
	}
	
	void merge(vector<int> &nums, int first, int mid, int last) {
		vector<int> tmp;
		int i = first;
		int j = mid + 1;
		while (i <= mid || j <= last) {
			int hi = i <= mid ? nums[i] : INT_MAX;
			int hj = j <= last ? nums[j] : INT_MAX;
			if (hi < hj) {
				tmp.push_back(hi);
				i++;
			} else {
				tmp.push_back(hj);
				j++;
			}
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
		
		mergeSort(nums, 0, nums.size() - 1); // sort(nums.begin(), nums.end()); // sort exist in <algorithm>
		const int target = 0;
		
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] < target) {
					j++;
					while (nums[j] == nums[j-1] && j < k) {
						j++;
					}
				} else if (nums[i] + nums[j] + nums[k] > target) {
					k--;
					while (nums[k] == nums[k+1] && j < k) {
						k--;
					}
				} else {
					result.push_back({ nums[i], nums[j], nums[k] });
					j++;
					k--;
					while (nums[j] == nums[j-1] && j < k) {
						j--;
					}
					
					while (nums[k] == nums[k+1] && j < k) {
						k++;
					}
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = s->threeSum(nums);
	
	cout << "Solution : " << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}