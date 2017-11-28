/*************************************************
* 1 is road, 0 is water, and num > 1 is tree.
* Cut tree from low to high
*************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
private:
	vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
public:
	int flatFields(int numRows, int numColumns, vector<vector<int>> fields) {
		vector<int> nums;
		if (fields.size() == 0 || fields[0].size() == 0 || fields[0][0] == 0) {
			return -1;
		}
		
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numColumns; j++) {
				if (fields[i][j] > 1) {
					nums.push_back(fields[i][j]);
				}
			}
		}
		
		sort(nums.begin(), nums.end());

		int result = 0;
		int startPosX = numRows - 1;
		int startPosY = numColumns - 1;
		for (int i = 0; i < nums.size(); i++) {
			int steps = 0;
			queue<pair<int, int>> curQueue;
		  vector<vector<bool>> visited(numRows, vector<bool>(numColumns, false));
			curQueue.push({startPosX, startPosY});
			bool isFind = false;
			while (!curQueue.empty() && !isFind) {
				queue<pair<int, int>> nextQueue;
				while (!curQueue.empty()) {
					auto t = curQueue.front();
					curQueue.pop();
					if (fields[t.first][t.second] == nums[i]) {
						isFind =true;
						result += steps;
						startPosX = t.first;
						startPosY = t.second;
						fields[t.first][t.second] = 1;
						break;
					}
					
					if (fields[t.first][t.second] > 1) {
						continue;
					}
					
					for (auto dir : dirs) {
						int x = t.first + dir.first;
						int y = t.second + dir.second;
						if (x < 0 || x >= numRows || y < 0 || y >= numColumns || visited[x][y]) {
							continue;
						}
						
						visited[x][y] = true;
						nextQueue.push({x, y});
					}
				}
				
				steps++;
				curQueue = nextQueue;
			}

			if (!isFind) {
				return -1;
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	/*vector<vector<int>> fields = {
		{1, 3, 0, 2},
		{1, 1, 3, 1}
	};*/
	vector<vector<int>> fields = {
		{1, 0},
		{3, 2}
	};
	
	cout << s->flatFields(2, 4, fields) << endl;
	
	
	delete s;
	return 0;
}

