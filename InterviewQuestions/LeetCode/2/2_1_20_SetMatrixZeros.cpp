/******************************************************
* Given a m * n matrix, if an element is 0, set its entire row and column to 0.
* Do it in place.
* Follow up: Did you use extra space?
* A straight forward solution using O(mn) space in probably a bad idea.
* A simple improvement uses O(m+n) space, but still not the best solution.
* Could you devise a constant space solution?
******************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(m*n), Space: O(m+n) */
	void setZeroes1(vector<vector<int>> &matrix) {
		if (matrix.size() == 0) {
			return;
		}
		
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<bool> row(m, false);
		vector<bool> column(n, false);
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					row[i] = column[j] = true;
				}
			}
		}
		
		for (int i = 0; i < m; i++) {
			if (row[i]) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		
		for (int j = 0; j < n; j++) {
			if (column[j]) {
				for (int i = 0; i < m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
	}
	
	/* Time: O(m*n), Space(1) */
	void setZeros2(vector<vector<int>> &matrix) {
		if (matrix.size() == 0) {
			return;
		}
		
		const int m = matrix.size();
		const int n = matrix[0].size();
		bool firstRowHasZero = false;
		bool firstColumnHasZero = false;
		
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) {
				firstColumnHasZero = true;
			}
		}
		
		for (int j = 0; j < n; j++) {
			if (matrix[0][j] == 0) {
				firstColumnHasZero = true;
			}
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 0; j <n; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] == 0;
				}
			}
		}
		
		if (firstColumnHasZero) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
		
		if (firstRowHasZero) {
			for (int j = 0; j < n; j++) {
				matrix[0][j] = 0;
			}
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<int>> matrix1 = {
		{ 1, 1, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 }
	};
	
	vector<vector<int>> matrix2 = {
		{ 1, 1, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 }
	};
	
	cout << "Original matrix:" << endl;
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[i].size(); j++) {
			cout << matrix1[i][j] << " ";
		}
		
		cout << endl;
	}
	
	s->setZeroes1(matrix1);
	cout << "Solution 1:" << endl;
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[i].size(); j++) {
			cout << matrix1[i][j] << " ";
		}
		
		cout << endl;
	}
	
	s->setZeroes1(matrix2);
	cout << "Solution 2:" << endl;
	for (int i = 0; i < matrix2.size(); i++) {
		for (int j = 0; j < matrix2[i].size(); j++) {
			cout << matrix2[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}