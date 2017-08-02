/******************************************************************
* The n-queens puzzle is the problem of placing n queens on an n*n
* chessboard such that no two queens attack each other.
*        a b c d e f g h
*     ---------------------
*     8| E E E Q E E E E |8
*     7| E E E E E E Q E |7
*     6| E E Q E E E E E |6
*     5| E E E E E E E Q |5
*     4| E Q E E E E E E |4
*     3| E E E E Q E E E |3
*     2| Q E E E E E E E |2
*     1| E E E E E Q E E |1
*     ---------------------
*        a b c d e f g h
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* Each solution contains a distinct board configuration of the n-queens'
* placement, where 'Q' and '.' both indicate a queen and an empty space
* respectively.
* For example, there exist two distincts to the 4-queens puzzle:
*  [
*    [
*      ".Q..",
*      "...Q",
*      "Q...",
*      "..Q."
*    ]
*    [
*      "..Q.",
*      "Q...",
*      "...Q",
*      ".Q.."
*    ]
*  ]
******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void solveNQueensAux(vector<int> &f, vector<vector<string>> &result, int row) {
		if (row == f.size()) {
			vector<string> solution;
			for (int i = 0; i < f.size(); i++) {
				string s(f.size(), '.');
				s[f[i]] = 'Q';
				solution.push_back(s);
			}
			
			result.push_back(solution);
			return;
		}
		
		for (int j = 0; j < f.size(); j++) {
			if (isValid(f, row, j)) {
				f[row] = j;
				solveNQueensAux(f, result, row + 1);
				f[row] = -1; // Can comment this
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
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<int> f(n, -1);
		solveNQueensAux(f, result, 0);
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	
	vector<vector<string>> result = s->solveNQueens(4);
	cout << "Solution:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << endl << "Result >>" << i + 1 << endl;
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << endl;
		}
	}
	
	delete s;
	return 0;
}