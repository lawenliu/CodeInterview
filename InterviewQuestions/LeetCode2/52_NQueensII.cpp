/******************************************************************
* Follow up for N-Queens problem.
* Now, instead outputing board configurations, return the total number
* of distinct solutions.
******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void totalNQueensAux(vector<int> &f, int &total, int row) {
		if (row == f.size()) {
			total++;
			return;
		}
		
		for (int j = 0; j < f.size(); j++) {
			if (isValid(f, row, j)) {
				f[row] = j;
				totalNQueensAux(f, total, row + 1);
				f[row] = -1;
			}
		}
	}
	
	bool isValid(vector<int> f, int row, int col) {
		for (int i = 0; i < row; i++) {
			if (f[i] == col || abs(i - row) == abs(f[i] - col)) {
				return false;
			}
		}
		
		return true;
	}
public:
	/* Time: O(n * n!), Space: O(n) */
	int totalNQueens(int n) {
		int total = 0;
		vector<int> f(n, -1);
		totalNQueensAux(f, total, 0);
		return total;
	}
};

int main(void) {
	Solution *s = new Solution();
	
	cout << "Solution: " << s->totalNQueens(4) << endl;
	
	delete s;
	return 0;
}