/*******************************************************
* A robot is located at the top-left corner of a m * n grid (marked "Start" in
* the diagram below).
* The robot can only move either down or right at any point in time. The robot
* is trying to reach the bottom-right corner of the grid (marked "Finish" in
* the diagram below).
* How many possible unique paths are there?
*    S - - - - - -
*    - - - - - - -
*    - - - - - - F
* Note: m and n will be at most 100.
*******************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int uniquePaths2Aux(vector<vector<int>> &f, int x, int y) {		
		
		if (x < 0 || y < 0) {
			return 0;
		}
		
		if (x == 0 && y == 0) {
			return f[0][0];
		}
		
		if (f[x][y] == 0) {
			
			f[x][y] = uniquePaths2Aux(f, x - 1, y) + uniquePaths2Aux(f, x, y - 1);			
		}
		
		return f[x][y];		
	}
	
public:
	/* Time: O(m^2 * n^2), Sace: O(1) */
	/* brute-force */
	int uniquePaths1(int m, int n) {
		if (m < 1 || n < 1) {
			return 0;
		}
		
		if (m == 1 && n == 1) {
			return 1;
		}
		
		return uniquePaths1(m - 1, n) + uniquePaths1(m, n - 1);
	}
	
	/* Time: O(m * n), Space: O(m * n) */
	/* memery */
	int uniquePaths2(int m, int n) {
		vector<vector<int>> f(m, vector<int>(n, 0));
		f[0][0] = 1;
		return uniquePaths2Aux(f, m - 1, n - 1);
	}
	
	/* Time: O(m * n), Space: O(n) */
	/* Dynamic Programming f[i][j] = f[i-1][j] = f[i][j-1] */
	int uniquePaths3(int m, int n) {
		vector<int> f(n, 0);
		f[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				f[j] = f[j] + f[j-1];
			}
		}
		
		return f[n-1];
	}
	
	/* Time: O(m + n), Space: O(1) */
	/* C(m+n-2, m-1) */
	int uniquePaths4(int m, int n) {
		int start = m + n - 2;
		int denominator = 1;
		int member = 1;
		
		for (int i = 0; i < m - 1; i++) {
			member *= start - i;
			denominator *= i + 1;
		}
		
		return (member / denominator);
	}
};

int main(void) {
	Solution* s = new Solution();
	
	cout << "Solution 1:" << s->uniquePaths1(3, 7) << endl;
	cout << "Solution 2:" << s->uniquePaths2(3, 7) << endl;
	cout << "Solution 3:" << s->uniquePaths3(3, 7) << endl;
	cout << "Solution 4:" << s->uniquePaths4(3, 7) << endl;
	
	delete s;
	return 0;
}