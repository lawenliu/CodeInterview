/************************************************************
* Given n non-negative integers representing an elevation map
* where the width of each bar is 1, compute how much water it
* is able to trap after raining.
* For example, given [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],
* return 6.
************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int trap1(const vector<int> &A) {
		if (A.size() < 2) {
			return 0;
		}
		
		int totalWater = 0;
		int curMax = A[0];
		int partSum = 0;
		for (int i = 1; i < A.size(); i++) {
			if (curMax <= A[i]) {
				totalWater += partSum;
				partSum = 0;
				curMax = A[i];
			} else {
				partSum += curMax - A[i];
			}
		}
		
		curMax = A[A.size()-1];
		partSum = 0;
		for (int i = A.size() - 2; i >= 0; i--) {
			if (curMax <= A[i]) {
				totalWater += partSum;
				partSum = 0;
				curMax = A[i];
			} else {
				partSum += curMax - A[i];
			}
		}
		
		return totalWater;
	}
	
	/* Time: O(n), Space: O(1) */
	int trap2(const vector<int> &A) {
		int maxHeightIndex = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[maxHeightIndex] < A[i]) {
				maxHeightIndex = i;
			}
		}
		
		int totalWater = 0;
		int curMax = 0;
		for (int i = 0; i < maxHeightIndex; i++) {
			if (curMax <= A[i]) {
				curMax = A[i];
			} else {
				totalWater += curMax - A[i];
			}
		}
		
		curMax = 0;
		for (int i = A.size() - 1; i > maxHeightIndex; i--) {
			if (curMax <= A[i]) {
				curMax = A[i];
			} else {
				totalWater += curMax - A[i];
			}
		}
		
		return totalWater;
	}
	
	/* Time: O(n), Space: O(n) */
	int trap3(const vector<int> &A) {
		const int n = A.size();
		if (n < 2) {
			return 0;
		}
		
		int *maxLeft = new int[n]();
		int *maxRight = new int[n]();
		int totalWater = 0;
		maxLeft[0] = 0;
		maxRight[n-1] = 0;
		
		for (int i = 1; i < n; i++) {
			maxLeft[i] = max(maxLeft[i-1], A[i-1]);
			maxRight[n-i-1] = max(maxRight[n-i], A[n-i]);
		}
		
		for (int i = 0; i < A.size(); i++) {
			int height = min(maxLeft[i], maxRight[i]);
			if (height > A[i]) {
				totalWater += height - A[i];
			}
		}
		
		delete []maxLeft;
		delete []maxRight;
		
		return totalWater;
	}
	
	/**/
	int trap4(const vector<int> &A) {
		stack<pair<int, int>> s;
		int totalWater = 0;
		for (int i = 0; i < A.size(); i++) {
			int lastHeight = 0;
			while (!s.empty()) {
				int height = s.top().first;
				int pos = s.top().second;
				totalWater += (min(height, A[i]) - lastHeight) * (i - pos - 1);
				
				if (A[i] < height) {
					break;
				} else {
					s.pop();
				}
				
				lastHeight = height;
			}
			
			s.push(make_pair(A[i], i));
		}
		
		return totalWater;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> A = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	
	cout << "Solution 1: " << s->trap1(A) << endl;
	cout << "Solution 2: " << s->trap2(A) << endl;
	cout << "Solution 3: " << s->trap3(A) << endl;
	cout << "Solution 4: " << s->trap4(A) << endl;
	
	delete s;
	return 0;
}
