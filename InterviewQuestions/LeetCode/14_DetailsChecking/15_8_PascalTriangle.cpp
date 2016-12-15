/*********************************
* Given numRows, generate the first numRows of Pascal's triangle.
* For example, given numRows = 5,
* Return
*         [1]
*        [1,1]
*       [1,2,1]
*      [1,3,3,1]
*     [1,4,6,4,1]
*********************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(n) */
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0) {
			return result;
		}
		
		vector<int> prev(1, 1);
		result.push_back(prev);
		
		for (int i = 1; i < numRows; i++) {
			vector<int> current(i + 1, 1);
			prev = result[i - 1];
			for (int j = 1; j < i; j++) {
				current[j] = (prev[j-1] + prev[j]);
			}
			
			result.push_back(current);
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	vector<vector<int>> result = s->generate(5);
	
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ",";
		}
		
		cout << endl;
	}
	
	
	delete s;
	return 0;
}