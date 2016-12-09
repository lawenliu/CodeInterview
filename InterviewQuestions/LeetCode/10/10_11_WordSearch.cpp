/***************************************************
* Given a 2D board and a word, find if the word exists in the grid.
* The word can be constructed from letters of sequentially adjacent
* cell, where "adjacent" cells are those horizontally or vertically
* neighbouring. The same letter cell may not be used more than once.
* For example, given board = 
*  [
*	 ["ABCE"],
*	 ["SFCS"],
*	 ["ADEE"]
*  ]
* word = "ABCCED", ->returns tre,
* word = "SEE", -> returns true,
* word = "ABCB", -> return false.
***************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	bool existAux(const vector<vector<char>> &board, const string &word, int index,
		int x, int y, vector<vector<bool>> &visited) {
		if (index == word.size()) {
			return true;
		}
		
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
			return false;
		}
		
		if (visited[x][y]) {
			return false;
		}
		
		if (board[x][y] != word[index]) {
			return false;
		}
		
		visited[x][y] = true; // use the visted as reference to save the memory
		bool result = existAux(board, word, index + 1, x - 1, y, visited)
						|| existAux(board, word, index + 1, x, y - 1, visited)
						|| existAux(board, word, index + 1, x + 1, y, visited)
						|| existAux(board, word, index + 1, x, y + 1, visited);
		visited[x][y] = false;
		return result;
	}
public:
	/* Time: O(n^2 * m^2), Space: O(n^2) */
	bool exist(const vector<vector<char>> &board, const string &word) {
		if (board.size() == 0) {
			return false;
		}
		
		const int m = board.size();
		const int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (existAux(board, word, 0, i, j, visited)) {
					return true;
				}
			}
		}
		
		return false;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<vector<char>> board = {
		{ 'A', 'B', 'C', 'E' },
		{ 'S', 'F', 'C', 'S' },
		{ 'A', 'D', 'E', 'E' }
	};
	string word1 = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";
	
	if (s->exist(board, word1)) {
		cout << word1 << " exist!" << endl;
	} else {
		cout << word1 << " not exist!" << endl;
	}
	
	if (s->exist(board, word2)) {
		cout << word2 << " exist!" << endl;
	} else {
		cout << word2 << " not exist!" << endl;
	}
	
	if (s->exist(board, word3)) {
		cout << word3 << " exist!" << endl;
	} else {
		cout << word3 << " not exist!" << endl;
	}
	
	delete s;
	return 0;
}