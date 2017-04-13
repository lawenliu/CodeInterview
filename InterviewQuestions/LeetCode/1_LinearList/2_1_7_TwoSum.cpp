/***************************************************
* Given an array of integers, find two numbers such that they add up to
* a specific target number.
* The function twoSum should return indices of the two numbers such that
* they add up to the target, where index1 must be less than index2. Please
* note that your returned answers (both index1 and index2) are not zero-based.
* You may assume that each input world have exactly one solution.
* Input: number = {2, 7, 11, 15}, target = 0;
* Ouput: index1 = 1, index2 = 2
***************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/* Hashmap to store the number and indice of the number */
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> indiceMap;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			indiceMap[nums[i]] = i;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			const int gap = target - nums[i];
			if (indiceMap.find(gap) != indiceMap.end() && indiceMap[gap] > i) {
				result.push_back(i + 1);
				result.push_back(indiceMap[gap] + 1);
				break;
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 2, 7, 11, 15 };
	
	vector<int> result = s->twoSum(nums, 9);
	cout << "Solution: " << endl;
	cout << "<" << result[0] << "," << result[1] << ">" << endl;
	
	delete s;
	return 0;
}