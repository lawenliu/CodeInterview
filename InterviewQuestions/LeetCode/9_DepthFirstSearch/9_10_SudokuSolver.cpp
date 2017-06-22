/**************************************************
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* Empty cells are indicated by the character '.'.
* You may assume that there will be only one unique solution.
* Sudo puzzle like this:
*      -------------------
*      |5|3|-|-|7|-|-|-|-|
*      |6|-|-|1|9|5|-|-|-|
*      |-|9|8|-|-|-|-|6|-|
*      |8|-|-|-|6|-|-|-|3|
*      |4|-|-|8|-|3|-|-|1|
*      |7|-|-|-|2|-|-|-|6|
*      |-|6|-|-|-|-|2|8|-|
*      |-|-|-|4|1|9|-|-|5|
*      |-|-|-|-|8|-|-|7|9|
*      -------------------
* Sudo solution like:
*      -------------------
*      |5|3|4|6|7|8|9|1|2|
*      |6|7|2|1|9|5|3|4|8|
*      |1|9|8|3|4|2|5|6|7|
*      |8|5|9|7|6|1|4|2|3|
*      |4|2|6|8|5|3|7|9|1|
*      |7|1|3|9|2|4|8|5|6|
*      |9|6|1|5|3|7|2|8|4|
*      |2|8|7|4|1|9|6|3|5|
*      |3|4|5|2|8|6|1|7|9|
*      -------------------
**************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	bool isValid(vector<vector<char>> &board, int x, int y) {
		for (int i = 0; i < 9; i++) {
			if (i != x && board[i][y] == board[x][y]) {
				return false;
			}
		}
		
		for (int j = 0; j < 9; j++) {
			if (j != y && board[x][j] == board[x][y]) {
				return false;
			}
		}
		
		for (int i = 3 * (x / 3); i < 3 * (x / 3) + 3; i++) {
			for (int j = 3 * (y / 3); j < 3 * (y / 3) + 3; j++) {
				if ((i != x || j != y) && board[i][j] == board[x][y]) {
					return false;
				}
			}
		}
		
		return true;
	}
public:
	/* Time: O(9^244), Space: O(1) */
	/* Time: T(1) = 9^4 */
	/* 		 T(n) = (9^3)(9+T(n-1)) */
	/* 		 T(n) = (9^3)(9+T(n-1)) */
	bool solveSudoku(vector<vector<char>> &board) {
		for (int i = 0; i < 9; i++) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') {
						for (int k = 0; k < 9; k++) {
							board[i][j] = '1' + k;
							if (isValid(board, i, j) && solveSudoku(board)) {
								return true;
							}
							
							board[i][j] = '.';
						}
						
						return false;
					}
				}
			}
		}
		
		return true;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<char>> board = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};
	
	bool result = s->solveSudoku(board);
	if (result) {
		cout << "Sudo:" << endl;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				cout << board[i][j] << ' ';
			}
			
			cout << endl;
		}
	} else {
		cout << "Not valid" << endl;
	}
	
	delete s;
	return 0;
}