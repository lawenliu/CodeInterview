#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] != '1') {
                    continue;
                }
                
                visited[i][j] = true;
                dfs(grid, i, j, visited);
                result++;
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<char>>& grid, int sX, int sY, vector<vector<bool>>& visited) {
        
        for (auto dir : dirs) {
            int nX = sX + dir[0];
            int nY = sY + dir[1];
            
            if (nX < 0 || nX >= grid.size() || nY < 0 || nY >= grid[0].size() || grid[nX][nY] != '1' || visited[nX][nY]) {
                continue;
            }
            
            visited[nX][nY] = true;
            dfs(grid, nX, nY, visited);
        }
    }
};

int main(void) {
	Solution *s = new Solution();
	vector<vector<char>> grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	
	cout << s->numIslands(grid);
	
	delete s;
	return 0;	
}