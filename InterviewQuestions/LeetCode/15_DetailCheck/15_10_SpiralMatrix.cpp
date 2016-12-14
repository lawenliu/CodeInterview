/***************************************
* Given a matrix of m*n elements (m rows, n columns), return all elements of the matrix in spiral order.
* For example, given the following matrix:
*        [
*						[1, 2, 3],
*						[4, 5, 6],
*						[7, 8, 9]
*					]
* you should return [1, 2, 3, 6, 9, 8, 7, 4, 5].
***************************************/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<int> spiralOrder1Aux(vector<vector<int>> &matrix, vector<int> result, int left, int right, int top, int bottom) {
		for (int i = left; i <= right; i++) {
			result.push_back(matrix[top][i]);
		}
		
		top++;
		if (top > bottom) {
			return result;
		}
		
		for (int i = top; i <= bottom; i++) {
			result.push_back(matrix[i][right]);
		}
		
		right--;
		if (right < left) {
			return result;
		}
		
		for (int i = right; i >= left; i--) {
			result.push_back(matrix[bottom][i]);
		}
		
		bottom--;
		if (bottom < top) {
			return result;
		}
		
		for (int i = bottom; i >= top; i--) {
			result.push_back(matrix[i][left]);
		}
		
		left++;
		if (left > right) {
			return result;
		}
		
		return spiralOrder1Aux(matrix, result, left, right, top, bottom);
	}
public:
	/* Time: O(n^2), Space: O(1) */
	vector<int> spiralOrder1(vector<vector<int>> &matrix) {
		vector<int> result;
		if (matrix.size() < 1 || matrix[0].size() < 1) {
			return result;
		}
		
		return spiralOrder1Aux(matrix, result, 0, matrix[0].size() - 1, 0, matrix.size() - 1);
	}
};

int main(void) {
	Solution* s = new Solution();
	
	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<vector<int>> matrix;
	vector<int> array1(num, num + 3);
	vector<int> array2(num + 3, num + 6);
	vector<int> array3(num + 6, num + 9);
	matrix.push_back(array1);
	matrix.push_back(array2);
	matrix.push_back(array3);
	
	vector<int> result = s->spiralOrder1(matrix);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ", ";
	}
	
	delete s;
	return 0;
}