/********************************************************
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations
* in C where the candidate number sums to T.
* The same repeated number may be chosen from C unlimited number of times.
* Note:
* 1. All numbers (including target) will be positive integers.
* 2. Elements in a combination(a1, a2, ..., ak) must be in non-decending order.
*    (ie, a1 <= a2 <= ... <= ak).
* 3. The solution set must not contain duplicate combinations.
* For example, given candidate 2, 3, 6, 7 and target 7, A solution set is:
*   [7]
*   [2, 2, 3]
********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	void quickSort(vector<int> &nums, int start, int end) {
		if (start >= end) {
			return;
		}
		
		int index = partition(nums, start, end);
		quickSort(nums, start, index - 1);
		quickSort(nums, index + 1, end);
	}
	
	int partition(vector<int> &nums, int start, int end) {		
		int pivot = nums[end];
		int j = start - 1;
		int i = start;
		while (i < end) {
			if (nums[i] < pivot) {
				j++;
				swap(nums[i], nums[j]);
			}
			
			i++;
		}
		
		j++;
		swap(nums[j], nums[end]);
		return j;
	}
	
	
	
	void combinationSumAux(vector<int> nums, vector<int> &path,
		vector<vector<int>> &result, int gap, int start) {
		if (gap == 0) {
			result.push_back(path);
			return;
		}
		
		int prev = -1;
		for (int i = start; i < nums.size(); i++) {
			if (gap < nums[i]) { // nums is sorted array.
				return;
			}
			
			if (prev == nums[i]) { // avoid duplicated result
				continue;
			}
			
			prev = nums[i];
			path.push_back(nums[i]);
			combinationSumAux(nums, path, result, gap - nums[i], i);
			path.pop_back();
		}
	}
public:
	/* Time: O(n!), Space: O(n) */
	vector<vector<int>> combinationSum(vector<int> &nums, int target) {
		quickSort(nums, 0, nums.size() - 1);
		vector<vector<int>> result;
		vector<int> path;
		combinationSumAux(nums, path, result, target, 0);
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums1 = { 2, 3, 6, 7 };
	vector<int> nums2 = { 10, 1, 2, 7, 6, 1, 5 };
	
	vector<vector<int>> result = s->combinationSum(nums1, 7);
	cout << "Solution :" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << "]" << endl;
	}
	
	
	result = s->combinationSum(nums2, 8);
	cout << endl << "Solution :" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << "]" << endl;
	}
	
	delete s;
	return 0;
}