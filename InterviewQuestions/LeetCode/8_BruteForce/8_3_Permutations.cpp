/***********************************************
* Given a collection of numbers, return all possible permutations.
* For example, [1, 2, 3] have the following permutations: [1, 2, 3], [1, 3, 2],
* [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
***********************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	void permuteAux(vector<int> nums, vector<int> &path, vector<vector<int>> &result) {
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		
		for (int i  = 0; i < nums.size(); i++) {
			auto pos = find(path.begin(), path.end(), nums[i]);
			
			if (pos == path.end()) {
				path.push_back(nums[i]);
				permuteAux(nums, path, result);
				path.pop_back();
			}
		}
	}
public:
	/* Time (n!), Space: O(n) */
	vector<vector<int>> permute(vector<int> &nums) {
		vector<vector<int>> result;
		vector<int> path;
		permuteAux(nums, path, result);
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 1, 2, 3 };
	
	vector<vector<int>> result = s->permute(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << "Permutation " << i + 1 << ":";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	delete s;
	return 0;
}