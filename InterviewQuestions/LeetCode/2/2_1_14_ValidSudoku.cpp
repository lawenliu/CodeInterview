/*************************************************************
* Determine if a Suduku is valid, according to: Sudoku Puzzles - The Rules:
* http://sudoku.com.au/TheRules.aspx.
* The Sudoku board could be partially filled where empty cells are filled
* with the character '.'.
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
*************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	bool check(char ch, bool used[9]) {
		if (ch == '.') {
			return true;
		}
		
		if (used[ch-'1']) {
			return false;
		}
		
		used[ch-'1'] = true;
		
		return true;
	}
public:
	bool isValidSudoku(const vector<vector<char>> &board) {
		bool used[9];
		for (int i = 0; i < 9; i++) {
			fill(used, used + 9, false);
			for (int j = 0; j < 9; j++) {
				if (!check(board[i][j], used)) {
					return false;
				}
			}
			
			fill(used, used + 9, false);
			for (int j = 0; j < 9; j++) {
				if (!check(board[i][j], used)) {
					return false;
				}
			}
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				fill(used, used + 9, false);
				for (int k = i * 3; k < i * 3 + 3; k++) {
					for (int l = j * 3; l < j * 3 + 3; l++) {
						if (!check(board[k][l], used)) {
							return false;
						}
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
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};
	
	cout << "Solution: " << s->isValidSudoku(board) << endl;
	
	
	delete s;
	return 0;
}