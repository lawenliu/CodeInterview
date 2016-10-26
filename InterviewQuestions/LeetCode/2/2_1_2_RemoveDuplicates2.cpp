/****************************************
* Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
* For example, Given sorted array A = [1, 1, 1, 2, 2, 3],
* Your function should return length = 5, and A is now [1, 1, 2, 2, 3]
****************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int removeDuplicates1(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		
		int start = 0;
		int duplicate = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[start] != nums[i] || duplicate < 2) {
				if (nums[start] != nums[i]) {
					duplicate = 0;
				}
				
				start++;
				nums[start] = nums[i];
			}
			
			duplicate++;
		}
		
		for (int i = nums.size() - 1; i > start; i--) {
			nums.pop_back();
		}
		
		return start + 1;
	}
	
	/* Time: O(n), Space: O(1) */
	int removeDuplicates2(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		
		int start = 1;
		int duplicate = 2;
		for (int i = 2; i < nums.size(); i++) {
			if (nums[start - 1] != nums[i]) {
				start++;
				nums[start] = nums[i];
			}
		}
		
		for (int i = nums.size() - 1; i > start; i--) {
			nums.pop_back();
		}
		
		return start + 1;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	
	cout << "Solution 1: " << s->removeDuplicates1(nums) << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ",";
	}
	
	cout << endl;
	cout << "Solution 2: " << s->removeDuplicates2(nums) << endl;
	
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ",";
	}
	
	delete s;
	return 0;
}