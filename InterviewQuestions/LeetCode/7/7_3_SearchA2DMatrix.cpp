/*******************************************
* Write an efficient algorithm that searches for a value in an m * n matrix.
* This matrix has the following properties:
* 1. Integers in each row are sorted from left to right.
* 2. The first integer of each row is greater than the last integer of the previous row.
* For example, Consider the following matrix:
* [
*	[1,  3,  5,  7],
*	[10, 11, 16, 20],
*	[23, 30, 34, 50]
* ]
* Given target = 3, return true.
*******************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(log(m*n), Space: O(1) */
	bool searchMatrix(const vector<vector<int>> &matrix, int target) {
		if (matrix.empty()) {
			return false;
		}
		
		int m = matrix.size();
		int n = matrix[0].size();
		int first = 0;
		int last = m * n - 1;
		while (first <= last) {
			int mid = (first + last) / 2;
			if (matrix[mid/n][mid%n] == target) {
				return true;
			} else if (matrix[mid/n][mid%n] < target) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}
		
		return false;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> nums1 = { 1, 3, 5, 7 };
	vector<int> nums2 = { 10, 11, 16, 20 };
	vector<int> nums3 = { 23, 30, 34, 50 };
	vector<vector<int>> matrix = { nums1, nums2, nums3 };
	
	cout << "Solution 1: " << s->searchMatrix(matrix, 3) << endl;
	cout << "Solution 1: " << s->searchMatrix(matrix, 8) << endl;
	
	delete s;
	return 0;
}
