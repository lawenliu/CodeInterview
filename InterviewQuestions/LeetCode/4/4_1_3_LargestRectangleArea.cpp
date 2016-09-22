/*************************************
* Given n non-negative integers representing the histogram's bar height where the width
* of each bar is 1, find the area of largest reactangle in the histogram.
* Given height = [2, 1, 5, 6, 2, 3], return 10.
*************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea1(vector<int> &height) {
		int largestArea = 0;
		int minHeight = 0;
		
		for (int i = 0; i < height.size(); i++) {
			minHeight = height[i];
			for (int j = i; j < height.size(); j++) {
				minHeight = min(minHeight, height[j]);
				largestArea = max(largestArea, minHeight * (j - i + 1));
			}
		}
		
		return largestArea;
	}
	
	int largestRectangleArea2(vector<int> &height) {
		int largestArea = 0;
		stack<int> s;
		height.push_back(0); // Used to deal with last one
		
		int left = 0;
		while (left < height.size()) {
			if (s.empty() || height[left] > height[s.top()]) {
				s.push(left);
				left++;
			} else {
				int topIndex = s.top();
				s.pop();
				int width = s.empty() ? left : left - s.top() - 1;
				largestArea = max(largestArea, height[topIndex] * width);
			}
		}
		
		return largestArea;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A1 = { 2, 1, 5, 6, 2, 3 };
	vector<int> A2 = { 2, 3, 5, 6, 2, 3 };
	
	cout << "Solution 1: " << s->largestRectangleArea1(A1) << endl;
	cout << "Solution 1: " << s->largestRectangleArea1(A2) << endl;
	cout << "Solution 2: " << s->largestRectangleArea2(A1) << endl;
	cout << "Solution 2: " << s->largestRectangleArea2(A2) << endl;
	
	delete s;
	return 0;
}
