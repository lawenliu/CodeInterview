/*****************************************
* Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
* For example, Given 3,
* You shuld return the following matrix:
*         [
*           [1, 2, 3],
*           [8, 9, 4],
*           [7, 6, 5]
*          ]
*****************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(1) */
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		int start = 0;
		int end = n - 1;
		int num = 1;
		
		while (start <= end) {
			for (int i = start; i <= end; i++) {
				result[start][i] = num;
				num++;
			}
			
			for (int i = start + 1; i <= end; i++) {
				result[i][end] = num;
				num++;
			}
			
			for (int i = end - 1; i >= start; i--) {
				result[end][i] = num;
				num++;
			}
			
			for (int i = end - 1; i >= start + 1; i--) {
				result[i][start] = num;
				num++;
			}
			
			start++;
			end--;
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	vector<vector<int>> result = s->generateMatrix(5);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++) {
		cout << result[i][j] << ",";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}
