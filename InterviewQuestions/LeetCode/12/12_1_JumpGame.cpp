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

class Solution {
public:
	/* Time O(n), Space O(1) */
	bool canJump1(const vector<int> &nums) {
		if (nums.size() < 2) {
			return true;
		}
		
		int maxLen = nums[0];		
		for (int i = 1; i < nums.size() && maxLen > 0; i++) {
			if (maxLen + i >= nums.size()) { // maxLen - 1 + i >= nums.size() - 1;
				return true;
			}
			
			maxLen = max(maxLen - 1, nums[i]);
		}
		
		return false;
	}
	
	/* Time: O(n), Space:O(1) */
	bool canJump2(const vector<int> &nums) {
		int reachIndex = 1;
		for (int i = 0; i < reachIndex && reachIndex < nums.size(); i++) {
			reachIndex = max(reachIndex, i + 1 + nums[i]);
		}
		
		return reachIndex >= nums.size();
	}
	
	
	/* f[i] is the remain steps from first to i. f[i] = max(f[i - 1], A[i-1]) - 1, i > 0 */
	/* Time: O(n), Space: O(n) */
	bool canJump3(const vector<int> &nums) {
		vector<int> f(nums.size(), 0);
		f[0] = 0;
		for (int i = 1; i < nums.size(); i++){
			f[i] = max(f[i - 1], nums[i - 1]) - 1;
			if(f[i] < 0) return false;
		}
		
		return f[nums.size() - 1] >= 0;
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