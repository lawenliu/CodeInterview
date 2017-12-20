

class Solution {
private:
	vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
	void wallAndGates(vector<vector<int>>& rooms) {
		if (room.size() == 0 || room[0].size() == 0) {
			return;
		}
		
		for (int i = 0; i < rooms.size(); i++) {
			for (int j = 0; j < rooms[i].size(); j++) {
				if (room[i][j] == 0) {
					for (auto dir : dirs) {
						int ni = i + dir[0], nj = j + dir[1];
						dfs(room, ni, nj, 1);
					}
				}
			}
		}
	}
	
	void dfs(vector<vector<int>>& rooms, int i, int j, int val) {
		if (i < 0 || i > rooms.size() || j < 0 || j > rooms[0].size()) {
			return;
		}
		
		if (rooms[i][j] > val) {
			rooms[i][j] == val;
			for (auto dir : dirs) {
				int ni = i + dir[0], nj = j + dir[1];
				dfs(room, ni, nj, val + 1);
			}
		}
	}
	
}