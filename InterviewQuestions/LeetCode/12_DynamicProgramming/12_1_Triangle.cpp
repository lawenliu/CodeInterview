/************************************
* Given a triangle, find the minimum path sum from top to bottom.
* Each step you may move to adjacent numbers on the row below.
* For example, given teh following triangle:
*               [2]
*             [3] [4]
*						[6]	[5] [7]
*         [4] [1] [8] [3]
* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
* Note: Bonus point if you are able to do this using only O(n) extra space,
* where n is the total number of rows in the triangle.
************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n ^ 2), Space: O(1): f(i, j) = min(f(i + 1, j), f(i + 1, j + 1))
			f(i,j): the minimum path sum from 0 to (i,j) */
	int minimumTotal1(vector<vector<int>> &triangle) {
		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < i + 1; j++) {
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		
		return triangle[0][0];
	}
	
	/* Time: O(n ^ 2), Space: O(n) */
	int minimumTotal2(vector<vector<int>> &triangle) {
		vector<int> curLine(&triangle[triangle.size() - 1][0], &triangle[triangle.size() - 1][0] + triangle.size());
		
		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < i + 1; j++) {
				curLine[j] = triangle[i][j] + min(curLine[j], curLine[j + 1]);
			}
		}
		
		return curLine[0];
	}
};

int main(void) {
	Solution* s = new Solution();
	
	vector<vector<int>> triangle1 = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	vector<vector<int>> triangle2 = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	
	cout << "Solution 1: " << s->minimumTotal1(triangle1) << endl; // Triangle is changed here, will affact the later call
	cout << "Solution 2: " << s->minimumTotal2(triangle2) <<endl;
	
	delete s;
	return 0;
}
