/********************************
* Given a 2D binary matrix filled with 0's and 1's, find the largest
* rectangle containing all ones and return its area.
********************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n ^ 2), Space: O(n) */
	int maximalRectangle(vector<vector<char>> &matrix) {
		if (matrix.empty()) {
			return 0;
		}
		
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> L(n, 0);
		vector<int> R(n, n);
		vector<int> H(n, 0);
		
		int maxRect = 0;
		for (int i = 0; i < m; i++) {
			int left = 0;
			int right = n;
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					H[j]++;
					L[j] = max(L[j], left);
				} else {
					left = j + 1;
					H[j] = 0;
					L[j] = 0;
					R[j] = n;
				}
			}
			
			for (int j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') {
					R[j] = min(R[j], right);
					maxRect = max(maxRect, (R[j] - L[j]) * H[j]);
				} else {
					right = j;
				}
			}
		}
		
		return maxRect;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<char>> matrix = { { '0', '1', '1', '1', '0', '0', '0', '0'	},
		{ '0', '1', '1', '1', '0', '1', '1', '0' }, { '0', '0', '0', '0', '0', '1', '1', '0' } };
	
	cout << "Solution 1: " << s->maximalRectangle(matrix) << endl;
	
	delete s;
	return 0;
}