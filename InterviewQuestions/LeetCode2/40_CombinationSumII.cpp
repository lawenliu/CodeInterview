/******************************************************
* Given a collection of candidate numbers (C) and a target
* number (T), find all unique combinations in C where the
* candidate numbers sums to T.
* Each number in C may only be used once in the combination.
* Note:
*  1. All numbers (including target) will be positive integers.
*  2. Elements in a combination (a1, a2, ..., ak) must be in
*     non-descending order. (ie, a1 <= a2 <= ... <= ak).
*  3. The solution set must not contain duplicate combinations.
* For example, given candidate set 10, 1, 2, 7, 6, 1, 5 and target 8,
* A solution set is:
*  [1, 7]
*  [1, 2, 5]
*  [2, 6]
*  [1, 1, 6]
******************************************************/
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
	
	void combinationSum2Aux(vector<int> nums, vector<int> &path,
		vector<vector<int>> &result, int gap, int start) {
	  if (gap == 0) {
			result.push_back(path);
			return;
		}
		
		int prev = -1;
		for (int i = start; i < nums.size(); i++) {
			if (gap < nums[i]) {
				return;
			}
			
			if (prev == nums[i]) {
				continue;
			}
			
			prev = nums[i];
			path.push_back(nums[i]);
			combinationSum2Aux(nums, path, result, gap - nums[i], i + 1);
			path.pop_back();
		}
	}
public:
	/**/
	vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
		quickSort(nums, 0, nums.size() - 1); // sort(nums.begin(), nums.end()); in algorithm		
		vector<vector<int>> result;
		vector<int> path;
		combinationSum2Aux(nums, path, result, target, 0);
	  return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 10, 1, 2, 7, 6, 1, 5 };
	
	vector<vector<int>> result = s->combinationSum2(nums, 8);
	cout << "Solution :" << endl;
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
