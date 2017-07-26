/*************************************************
* You are given an n * n 2D matrix representing an image.
* Rotate the image by 90 degree( clockwise).
* Follow up: Could you do this in-place?
*************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(1) */
	/* Flip based on secondary diagonal, then flip based on horizontal middle line */
	void rotate1(vector<vector<int>> &matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
			}
		}
		
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
	}
	
	/* Time: O(n^2), Space: O(1) */
	/* Flip based on horizontal middle line, then flip based on main diagonal */
	void rotate2(vector<vector<int>> &matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<int>> matrix1 = {
		{ 1, 2 },
		{ 3, 4 }
	};
	vector<vector<int>> matrix2 = {
		{ 1, 2 },
		{ 3, 4 }
	};
	
	cout << "Original Matrix:" << endl;
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1.size(); j++) {
			cout << matrix1[i][j] << " ";
		}
		
		cout << endl;
	}
	
	s->rotate1(matrix1);
	cout << endl << "Result 1:" << endl;
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[0].size(); j++) {
			cout << matrix1[i][j] << " ";
		}
		
		cout << endl;
	}
	
	s->rotate2(matrix2);
	cout << endl << "Result 2:" << endl;
	for (int i = 0; i < matrix2.size(); i++) {
		for (int j = 0; j < matrix2[0].size(); j++) {
			cout << matrix2[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}