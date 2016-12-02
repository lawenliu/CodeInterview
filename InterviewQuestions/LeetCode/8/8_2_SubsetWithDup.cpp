/******************************************************
* Given a collection of integers that might contain duplicates, S, return
* all possible subsets.
* Note:
* Elements in a subset must be in non-descending order. The solution set
* must not contain duplicate subsets. For example, If S = [1, 2, 2], a solution is:
*  [
*	 [2],
*	 [1],
*	 [1, 2, 2],
*	 [2, 2],
*	 [1, 2],
*	 []
*  ]
******************************************************/
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
	
	void subsetsWithDupAux(vector<int> S, vector<int> &path, int step, vector<vector<int>> &result) {
		result.push_back(path);
		
		for (int i = step; i < S.size(); i++) {
			if (i != step && S[i] == S[i-1]) {
				continue;
			}
			
			path.push_back(S[i]);
			subsetsWithDupAux(S, path, i + 1, result);
			path.pop_back();
		}
	}
public:
	/* Time: O(2^n), Time: O(n) */
	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		mergeSort(S, 0, S.size() - 1);
		vector<vector<int>> result;
		vector<int> path;
		subsetsWithDupAux(S, path, 0, result);
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> S = { 1, 2, 2 };
	
	vector<vector<int>> result = s->subsetsWithDup(S);
	cout << "Solution 1: " << endl;
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