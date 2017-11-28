#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string findShortestWay(vector<vector<int>> maze, vector<int>& ball, vector<int>& hole) {
		if (maze.size() == 0 || maze[0].size() == 0) {
			return "impossible";
		}
		
		int m = maze.size(), n = maze[0].size();
		vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
		unordered_map<int, string> paths;
		vector<char> ways = {'u', 'd', 'l', 'r'};
		queue<pair<int, int>> q;
		dists[ball[0]][ball[1]] = 0;
		q.push({ball[0], ball[1]});
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (int i = 0; i < dirs.size(); i++) {
				int x = t.first, y = t.second, dist = dists[x][y];
				string path = paths[x*n+y];
				while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && (x != hole[0] || y != hole[1])) {
					x += dirs[i][0];
					y += dirs[i][1];
					dist++;
				}
				
				if (x != hole[0] || y != hole[1]) {
					x -= dirs[i][0];
					y -= dirs[i][1];
				}
				
				path.push_back(ways[i]);
				if (dists[x][y] > dist) {
					dists[x][y] = dist;
					paths[x*n+y] = path;
					if (x != hole[0] || y != hole[1]) {
						q.push({x, y});
					}
				} else if (dists[x][y] == dist && paths[x*n+y].compare(path) > 0) {
					paths[x*n+y] = path;
					if (x != hole[0] || y != hole[1]) {
						q.push({x, y});
					}
				}
			}
		}
		
		string res = paths[hole[0]*n+hole[1]];
		return res.empty() ? "impossible" : res;
	}
};

int main(void) {
	Solution *s = new Solution();
	
	vector<vector<int>> maze1 = {
		{0, 0, 0, 0, 0},
			{1, 1, 0, 0, 1},
				{0, 0, 0, 0, 0},
					{0, 1, 0, 0, 1},
						{0, 1, 0, 0, 0}
	};
	vector<int> hole1 = {0, 1};
	vector<int> ball1 = {4, 3};
	
	vector<int> hole2 = {4, 3};
	vector<int> ball2 = {3, 0};
	
	cout << s->findShortestWay(maze1, ball1, hole1) << endl;
	cout << s->findShortestWay(maze1, ball2, hole2) << endl;
	
	delete s;
	return 0;
}