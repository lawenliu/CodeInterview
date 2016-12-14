/***************************************************
* Given an unsorted array of integers, find the length of the longest
* consecutive elements sequence.
* For example, given [100, 4, 200, 1, 3, 2], the longest consecutive
* elements sequence is [1, 2, 3, 4]. Return its length 4.
* Your algorithm should run in O(n) complexity.
***************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(n) */
	int longestConsecutive1(const vector<int> nums) {
		unordered_map<int, bool> used;
		
		for (int i = 0; i < nums.size(); i++)  {
			used[nums[i]] = false;
		}
		
		int longest = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (used[nums[i]]) {
				continue;
			}
			
			int len = 1;
			used[nums[i]] = true;
			for (int j = nums[i] + 1; used.find(j) != used.end(); j++) {
				used[j] = true;
				len++;
			}
			
			for (int j = nums[i] - 1; used.find(j) != used.end(); j--) {
				used[j] = true;
				len++;
			}
			
			longest = max(longest, len);
		}
		
		return longest;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };
	cout << "Solution 1: " << s->longestConsecutive1(nums);
	
	delete s;
	return 0;
}