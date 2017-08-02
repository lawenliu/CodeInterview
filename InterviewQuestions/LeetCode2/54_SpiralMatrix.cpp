/*******************************************************
* Given a matrix of m*n elements (m rows, n columns), return
* all elements of the matrix in spiral order.
* For example,
* Given the following matrix:
*  [
*    [1, 2, 3],
*    [4, 5, 6],
*    [7, 8, 9]
*  ]
* You should return [1, 2, 3, 6, 9, 8, 7, 4, 5].
*******************************************************/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	void spiralOrder1Aux(vector<vector<int>> &matrix,
   	vector<int> &result, int left, int right, int top, int bottom) {
		for (int j = left; j <= right; j++) {
			result.push_back(matrix[top][j]);
		}
		
		top++;
		if(top > bottom) {
			return;
		}
		
		for (int i = top; i <= bottom; i++) {
			result.push_back(matrix[i][right]);
		}
		
		right--;
		if (right < left) {
			return;
		}
		
		for (int j = right; j >= left; j--) {
			result.push_back(matrix[bottom][j]);
		}
		
		bottom--;
		if (bottom < top) {
			return;
		}
		
		for (int i = bottom; i >= top; i--) {
			result.push_back(matrix[i][left]);
		}
		
		left++;
		if (left > right) {
			return;
		}
		
		spiralOrder1Aux(matrix, result, left, right, top, bottom);
	}
public:
	/* Time: O(n^2), Space; O(1) */
	vector<int> spiralOrder1(vector<vector<int>> &matrix) {
		vector<int> result;
		if (matrix.size() < 1 || matrix[0].size() < 1) {
			return result;
		}
		
		spiralOrder1Aux(matrix, result, 0, matrix[0].size() - 1, 0, matrix.size() - 1);
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	
	vector<int> result = s->spiralOrder1(matrix);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ", ";
	}
	
	delete s;
	return 0;
}
