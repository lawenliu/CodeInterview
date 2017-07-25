/*******************************************************
* Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
* For example,
*  X X X X
*  X O O X
*  X X O X
*  X O X X
* After running your function, the board should be:
*  X X X X
*  X X X X
*  X X X X
*  X O X X
*******************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
	bool isValidState(vector<vector<char>> board, pair<int, int> s) {
		const int m = board.size();
		const int n = board[0].size();
		const int x = s.first;
		const int y = s.second;
		if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
			return false;
		}
		
		return true;
	}
	
	vector<pair<int, int>> stateExtend(vector<vector<char>> &board, pair<int, int> s) {
		vector<pair<int, int>> result;
		const int m = board.size();
		const int n = board[0].size();
		const int x = s.first;
		const int y = s.second;
		
		const pair<int, int> newStates[4] = { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
		for (auto state : newStates) {
			if (isValidState(board, state)){
				board[state.first][state.second] = '*';
				result.push_back(state);
			}
		}
		
		return result;
	}
	
	void solveAux(vector<vector<char>> &board, int x, int y) {
		const int m = board.size();
		const int n = board[0].size();
		queue<pair<int, int>> cur, next;
		pair<int, int> start = { x, y };
		if (isValidState(board, start)) {
			board[x][y] = '*';
			cur.push(start);
		}
		
		// Please try to use breadth first search: go through cur queue first.
		while(!cur.empty()) {
			auto state = cur.front();
			cur.pop();
			auto newStates = stateExtend(board, state);
			for (auto s : newStates) {
				next.push(s);
			}
			
			swap(cur, next);
		}
	}
public:
	/* Time: O(n^2), Space: O(n) */
	/* We find 'O' instead of 'X' from outside to inside */
	void solve(vector<vector<char>> &board) {
		if (board.empty()) {
			return;
		}
		
		const int m = board.size();
		const int n = board[0].size();
		for (int i = 0; i < m; i++) {
			solveAux(board, i, 0);
			solveAux(board, i, n - 1);
		}
		
		for (int j = 0; j < n; j++) {
			solveAux(board, 0, j);
			solveAux(board, m - 1, j);
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				} else if (board[i][j] == '*') {
					board[i][j] = 'O';
				}
			}
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<char>> board = { 
		{'X', 'X', 'X', 'X', 'X'},
		{'X', 'O', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'X', 'X', 'X'}
	};
	
	s->solve(board);
	
	cout << "Solution: " << endl;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}