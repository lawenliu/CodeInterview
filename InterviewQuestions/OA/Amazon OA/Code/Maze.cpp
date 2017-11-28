/**********************************************************
* Check whether mouse can reach the cheese from point {0,0}
* 0 is wall, 1 is road, 9 is cheese
**********************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	bool mazeCheck(vector<vector<int>> maze, pair<int, int> start) {
		if (maze.size() == 0 || maze[0].size() == 0) {
			return false;
		}
		
		if (maze[start.first][start.second] == 9) {
			return true;
		}
		
		int m = maze.size();
		int n = maze[0].size();
		vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<vector<int>> visited(m, vector<int>(n, 0));
		queue<pair<int, int>> curQueue;
		curQueue.push(start);
		visited[start.first][start.second] = 1;
		while (!curQueue.empty()) {
			queue<pair<int, int>> nextQueue;
			while (!curQueue.empty()) {
				pair<int, int> point = curQueue.front();
				curQueue.pop();
				for (auto dir : dirs) {
					int x = dir.first + point.first;
					int y = dir.second + point.second;
					if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0) {
						if (maze[x][y] == 9) {
							return true;
						} else if (maze[x][y] == 1) {
							nextQueue.push({x, y});
							visited[x][y] = 1;
						}
					}
				}
			}
			
			curQueue = nextQueue;
		}
		
		return false;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<vector<int>> maze1 = {
		{1,0,0,0,0},
		{1,1,1,1,1},
		{1,0,0,0,0},
		{0,0,9,0,0}
	};
	
	vector<vector<int>> maze2 = {
		{1,0,0,0,0},
		{1,1,1,1,1},
		{1,0,0,0,1},
		{0,0,9,1,1}
	};
	
	vector<vector<int>> maze3 = {
		{1,1,1,1},
		{1,0,0,0},
		{1,9,0,0}
	};
	
	vector<vector<int>> maze4 = {
		{9}
	};
	
	vector<vector<int>> maze5 = {
		{1,1,1,1,1,1},
		{1,1,1,1,0,0},
		{0,0,1,0,0,0},
		{1,1,1,1,1,1},
		{1,0,0,0,1,0},
		{1,1,1,0,9,0}
	};
	
	
	cout << "result: " << s->mazeCheck(maze5, {0, 0});
	
	delete s;
	return 0;
}