/*********************************************************************
* Given a collection of numbers that might contain duplicates, return
* all possible unique permutations.
* For example,
* [1, 1, 2] have the following unique permutations:
* [1, 1, 2], [1, 2, 1] and [2, 1, 1].
*********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
private:
	void permuteUniqueAux(unordered_map<int, int> elements, vector<int> &path, int n, vector<vector<int>> &result) {
		if (path.size() == n) {
			result.push_back(path);
			return;
		}
		
		for (auto it = elements.begin(); it != elements.end(); it++) {
			int count = 0;
			for (int i = 0; i < path.size(); i++) {
				if (it->first == path[i]) {
					count++;
				}
			}
			
			if (count < it->second) {
				path.push_back(it->first);
				permuteUniqueAux(elements, path, n, result);
				path.pop_back();
			}
		}
	}
public:
	/* Time: O(n!), Space: O(n) */
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		unordered_map<int, int> countMap;
		for (int i = 0; i < nums.size(); i++) {
			if (countMap.find(nums[i]) != countMap.end()) {
				countMap[nums[i]]++;
			} else {
				countMap[nums[i]] = 1;
			}
		}
		
		permuteUniqueAux(countMap, path, nums.size(), result);
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> nums = { 1, 1, 2 };
	vector<vector<int>> result = s->permuteUnique(nums);
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
