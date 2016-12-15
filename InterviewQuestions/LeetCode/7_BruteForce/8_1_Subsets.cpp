/*******************************************************
* Given a set of distinct integers, S, return all possible subsets.
* Note:
* 1. Elements in a subset must be in non-descending order.
* 2. The solution set must not contain duplicate subsets.
* For example, If S = [1, 2, 3], a solution is:
* [
*	[3],
*	[1],
*	[2],
*	[1, 2, 3],
*	[1, 3],
*	[2, 3],
*	[1, 2],
*	[]
* ]
*******************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	void mergeSort(vector<int> &nums, int first, int last) {
		if (first >= last) {
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
		
		for (int k = first; k <= last; k++) {
			nums[k] = tmp[k-first];
		}
	}
	
	void subsets1Aux(vector<int> S, vector<int> &path, int step, vector<vector<int>> &result) {
		if (step == S.size()) {
			result.push_back(path);
			return;
		}
		
		subsets1Aux(S, path, step + 1, result);
		path.push_back(S[step]);
		subsets1Aux(S, path, step + 1, result);
		path.pop_back();
	}
	
	void subsets2Aux(vector<int> S, vector<bool> &selected, int step, vector<vector<int>> &result) {
		if (step == S.size()) {
			vector<int> subset;
			for (int i = 0; i < selected.size(); i++) {
				if (selected[i]) {
					subset.push_back(S[i]);
				}
			}
			
			result.push_back(subset);
			return;
		}
		
		selected[step] = false;
		subsets2Aux(S, selected, step + 1, result);
		selected[step] = true;
		subsets2Aux(S, selected, step + 1, result);
	}
public:
	/* Time: O(2^n), Time: O(n) */
	vector<vector<int>> subsets1(vector<int> &S) {
		mergeSort(S, 0, S.size() - 1);
		vector<vector<int>> result;
		vector<int> path;
		subsets1Aux(S, path, 0, result);
		return result;
	}
	
	/* Time: O(2^n), Time: O(n) */
	vector<vector<int>> subsets2(vector<int> &S) {
		mergeSort(S, 0, S.size() - 1);
		vector<vector<int>> result;
		vector<bool> selected( S.size(), false);
		subsets2Aux(S, selected, 0, result);
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> S = { 1, 3, 2 };
	
	vector<vector<int>> result = s->subsets1(S);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "subset " << i + 1 << endl;
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	result = s->subsets2(S);
	cout << "Solution 2: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "subset " << i + 1 << endl;
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}