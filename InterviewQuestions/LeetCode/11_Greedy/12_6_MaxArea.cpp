/********************************
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* Note: You may not slant the container.
********************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int maxArea(vector<int> &height) {
		int left = 0;
		int right = height.size() - 1;
		int maxArea = 0;
		
		while (left < right) {
			int curArea = min(height[left], height[right]) * (right - left);			
			maxArea = max(maxArea, curArea);
			
			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		
		return maxArea;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> height1 = { 2, 1, 5, 6, 2, 3 };
	vector<int> height2 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1 , 2, 1 };
	
	cout << "Solution : " << s->maxArea(height1) << endl;
	cout << "Solution : " << s->maxArea(height2) << endl;
	
	delete s;
	
	return 0;
}