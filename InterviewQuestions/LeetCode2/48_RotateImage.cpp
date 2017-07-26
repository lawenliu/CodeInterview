/*************************************************************
* You are given an n*n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(1) */
	/* Flip based on secondary diagonal, then flip based on horizontal middle line */
	void rotate(vector<vector<int>> &matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1 - i; j++) {
				swap(matrix[i][j], matrix[n-1-j][n-1-i]);
			}
		}
		
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				swap(matrix[i][j], matrix[n-1-i][j]);
			}
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<int>> matrix = {
		{ 1, 2 },
		{ 3, 4 }
	};
	
	cout << "Original Matrix:" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			cout << matrix[i][j] << " ";
		}
		
		cout << endl;
	}
	
	s->rotate(matrix);
	cout << endl << "Result 1:" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}
