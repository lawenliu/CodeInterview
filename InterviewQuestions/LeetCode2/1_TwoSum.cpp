/*********************************************************
* Given an array of integers, return indices of the
* two numbers such that they add up to a specific
* target.
* You may assume that each input would have exactly
* one solution.
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
* Update(2016/02/13):
* The return format had been changed to zero-based indices.
* Please read the above updated description carefully.
***********************************************************/
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
Analysis
  1. Use brute-force to find the two indices. The time complication of solution is O(n^2) which will time-out.
  2. Sort the array first, and then use two point to find the two indices, but you have to record the indices when you sort the array. So time complication will be O(nlogn), space to be O(n).
  3. Using HashMap to record the number and indices of the number
*/

class Solution {
public:
	/* Use brute-force with Time Limit Exceeded */
	/* Time: O(n^2), Space: O(1) */
	vector<int> twoSum1(vector<int> &nums, int target) {
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					result.push_back(i + 1);
					result.push_back(j + 1);
					break;
				}
			}
		}
		
		return result;
	}
	
	/* Use Hashmap to store the number and indices of number */
	/* Time: O(n), Space: O(n) */
	vector <int> twoSum2(vector<int> &nums, int target) {
		vector<int> result;
		unordered_map<int, int> indicesMap;
		for (int i  = 0; i < nums.size(); i++) {
			indicesMap[nums[i]] = i;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			int gap = target - nums[i];
			if (indicesMap.find(gap) != indicesMap.end() && i < indicesMap[gap]) {
				result.push_back(i + 1);
				result.push_back(indicesMap[gap] + 1);
				break;
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 2, 7, 11, 15 };
	vector<int> result = s->twoSum1(nums, 9);
	cout << "Solution 1 Result: <" << result[0] << "," << result[1] << ">" << endl;
	
	result = s->twoSum2(nums, 9);
	cout << "Solution 2 Result: <" << result[0] << "," << result[1] << ">" << endl;
	
	return 0;
}