/*******************************************
* Follow up for "Unique Paths":
* Now consider if some obstacles are added to the grids.
* How may unique paths would there be?
* An obstacle and empty space is marked as 1 and 0 respectively in the grid.
* For example, There is one obstacle in the middle of a 3 * 3 grid as illustrated below.
*  [
*	 [0, 0, 0],
*	 [0, 1, 0],
*	 [0, 0, 0]
*  ]
* The total number of unique paths is 2.
* Note: m and n will be at most 100.
*******************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int uniquePathsWithObstacles1Aux(const vector<vector<int>> obstacleGrid,
		vector<vector<int>> &f, int x, int y) {
		if (x < 0 || y < 0) {
			return 0;
		}
		
		if (obstacleGrid[x][y] == 1) {
			return 0;
		}
		
		if (x == 0 && y == 0) {
			return f[x][y];
		}
		
		f[x][y] = uniquePathsWithObstacles1Aux(obstacleGrid, f, x - 1, y)
					+ uniquePathsWithObstacles1Aux(obstacleGrid, f, x, y - 1);
					
		return f[x][y];
	}
public:
	/* Time: O(m * n), O (m * n) */
	/* f[i][j] = 0, i < 0 || j < 0 */
	/* f[i][j] = 1, i == 0 || j == 0 */
	/* f[i][j] = 0, ob[i][j] == 1 */
	/* f[i][j] = f[i-1][j] + f[i][j-1] */
	int uniquePathsWithObstacles1(vector<vector<int>> &obstacleGrid) {
		if (obstacleGrid.size() == 0) {
			return 0;
		}
		
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		vector<vector<int>> f(m, vector<int>(n, 0));
		
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
			return 0;
		}
		
		f[0][0] = 1;
		uniquePathsWithObstacles1Aux(obstacleGrid, f, m - 1, n - 1);
		return f[m-1][n-1];
	}
	
	int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid) {
		if (obstacleGrid.size() == 0) {
			return 0;
		}
		
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		vector<int> f(n, 0);
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
			return 0;
		}
		
		f[0] = 1;
		for (int i = 0; i < m; i++) {
			f[0] = f[0] == 0 || obstacleGrid[i][0] == 1 ? 0 : 1;
			for (int j = 1; j < n; j++) {
				f[j] = obstacleGrid[i][j] == 1 ? 0 : f[j] + f[j-1];
			}
		}
		
		return f[n-1];
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<int>> obstacleGrid = {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};
	cout << "Solution 1:" << s->uniquePathsWithObstacles1(obstacleGrid) << endl;
	cout << "Solution 2:" << s->uniquePathsWithObstacles2(obstacleGrid) << endl;
	
	delete s;
	return 0;
}
