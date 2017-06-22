/********************************
* Give an array of non-negtive integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position.
* Determine if you are able to reach the last index.
* For example:
* A = [2, 3, 1, 1, 4], return true.
* A = [3, 2, 1, 0, 4], return false.
********************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Assume the array can jump to end, or return 0 */
class Solution {
public:
	/* Time O(n), Space O(1) */
	int canJump1(const vector<int> &nums) {
		if (nums.size() < 2) {
			return 0;
		}
		
		int maxLen = nums[0];
		int step = 1;
		for (int i = 1; i < nums.size() && maxLen > 0; i++) {
			if (maxLen + i >= nums.size()) { // maxLen - 1 + i >= nums.size() - 1;
				return step;
			}
			
			maxLen = maxLen - 1;
			if(nums[i] > maxLen - 1) {
				maxLen = nums[i];
				step++;
			}
			
		}
		
		return 0;
	}
	
	/* Time: O(n), Space:O(1) */
	int canJump2(const vector<int> &nums) {
		int step = 0;
		int left = 0;
		int reachMost = 0;
		
		if (nums.size() < 2) {
			return 0;
		}
		
		while (left <= reachMost) {
			step++;
			int old_left = left;
			int old_reachMost = reachMost;
			
			while (old_left <= old_reachMost) {
				int new_reachMost = old_left + nums[old_left];
				if (new_reachMost >= nums.size() - 1) {
					return step;
				}
				
				if (new_reachMost > reachMost) {
					reachMost = new_reachMost;
				}
				
				old_left++;
			}
			
			left = old_reachMost + 1;
		}
		
		return 0;
	}
	
	
	/* Time: O(n), Space: O(1) */
	int canJump3(const vector<int> &nums) {
		int step = 0;
		int reachMost = 0;
		int next_reachMost = 0;
		for (int i = 0; i < nums.size(); i++){
			if (i > reachMost) {
				reachMost = next_reachMost;
				step++;
			}
			
			next_reachMost = max(next_reachMost, i + nums[i]);
		}
		
		return reachMost >= nums.size() - 1 ? step : 0;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A1 = { 2, 3, 1, 1, 4 };
	vector<int> A2 = { 3, 2, 1, 0, 4 };
	
	cout << "First solution" << endl;
	cout << s->canJump1(A1) << endl;
	cout << s->canJump1(A2) << endl;
	
	cout << "Second solution" << endl;
	cout << s->canJump2(A1) << endl;
	cout << s->canJump2(A2) << endl;
	
	cout << "Third solution" << endl;
	cout << s->canJump3(A1) << endl;
	cout << s->canJump3(A2) << endl;
	
	delete s;
	
	return 0;
}