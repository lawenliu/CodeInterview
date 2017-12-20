/*******************************************
* Given two sparse matrices A and B, return the result of AB.
* You may assume that A's column number is equal to B's row number.
* Example:
* A = [
*		[1, 0, 0],
*		[-1, 0, 3]
*]
* B = [
* 	[7, 0, 0],
*		[0, 0, 0],
*		[0, 0, 1]
*]
* AB = [
*		[7, 0, 0],
*		[-7, 0, 3]
*]
*******************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
		
		for (int i = 0; i < A.size(); i++) {
			for (int k = 0; k < A[0].size(); k++) {
				if (A[i][k] != 0) {
					for (int j = 0; j < B[0].size(); j++) {
						if (B[k][j] != 0) {
							result[i][j] += A[i][k] * B[k][j];
						}
					}
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<vector<int>> A = {
		{1, 0, 0},
		{-1, 0, 3}
	};
	
	vector<vector<int>> B = {
		{7, 0, 0},
		{0, 0, 0},
		{0, 0, 1}
	};
	
	
	vector<vector<int>> result = s->multiply(A, B);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++) {
			cout << result[i][j] << ",";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}

