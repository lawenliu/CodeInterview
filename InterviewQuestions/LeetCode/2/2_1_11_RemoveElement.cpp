/**********************************************************
* Given an array and a value, remove all instances of that value in place
* and return the new length.
* The order of elements can be changed. It doen't matter what you leave
* beyond the new length.
**********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int> &nums, int target) {
		int index = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != target) {
				nums[index] = nums[i];
				index++;
			}
		}
		
		return index;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums = { 1, 2, 3, 3, 2, 1, 3 };
	int len = s->removeElement(nums, 3);
	cout << "Solution: " << len << endl;
	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
	
	delete s;
	return 0;
}