/**********************************
* Given a m * n grid filled with non-negative numbers, find a path from top left to bottom right which
* minimize the sum of all numbers along its path.
* Note: You can only move either down or right at any point in time.
**********************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int minPathSum1Aux(vector<vector<int>> &grid, int m, int n) {
		if (m == -1 || n == -1) {
			return INT_MAX;
		}
		
		if (m == 0 && n == 0) {
			return grid[0][0];
		}
		
		return min(minPathSum1Aux(grid, m - 1, n), minPathSum1Aux(grid, m, n - 1)) + grid[m][n];
	}
public:
	/* Time: O(n!), Space: O(1) */
	int minPathSum1(vector<vector<int>> &grid) {
		if (grid.size() < 1 || grid[0].size() < 1) {
			return INT_MAX;
		}
			
		return minPathSum1Aux(grid, grid.size() - 1, grid[0].size() - 1);
	}
	
	/* Time: O(m * n), Space: O(m * n) */
	/* f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j] 
			f[i][j] is the min path sum from (0,0) to (i,j) */
	int minPathSum2(vector<vector<int>> &grid) {
		if (grid.size() < 1 || grid[0].size() < 1) {
			return INT_MAX;
		}
		
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> f(m, vector<int>(n, INT_MAX));
		
		f[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			f[i][0] = f[i-1][0] + grid[i][0];
		}
		
		for (int j = 1; j < n; j++) {
			f[0][j] = f[0][j-1] + grid[0][j];
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
			}
		}
		
		return f[m-1][n-1];
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<int>> grid1 = {{3, 2, 4, 5, 3}, {7, 2, 3, 1, 8}, {8, 4, 6, 2, 9}};
	vector<vector<int>> grid2 = {{3, 2, 4, 5, 3}};
	vector<vector<int>> grid3 = {{3}};
	
	cout << "Solution 1 :" << s->minPathSum1(grid1) << endl;
	cout << "Solution 1 :" << s->minPathSum1(grid2) << endl;
	cout << "Solution 1 :" << s->minPathSum1(grid3) << endl;
	
	cout << "Solution 2 :" << s->minPathSum2(grid1) << endl;
	cout << "Solution 2 :" << s->minPathSum2(grid2) << endl;
	cout << "Solution 2 :" << s->minPathSum2(grid3) << endl;
	
	delete s;
	return 0;
}