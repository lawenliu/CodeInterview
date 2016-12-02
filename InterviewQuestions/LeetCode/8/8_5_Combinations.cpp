/***********************************************************
* Given two integers n and k, return all possible combinations of k numbers out of 1...n.
* For example, If n = 4 and k = 2, a solution is:
*  [
* 	 [2, 4],
*	 [3, 4],
*	 [2, 3],
*	 [1, 2],
*	 [1, 3],
*	 [1, 4]
*  ]
***********************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	void combineAux(int n, int k, int start, int cur, vector<int> &path, vector<vector<int>> &result) {
		if (cur == k) {
			result.push_back(path);
			return;
		}
		
		for (int i  = start; i <= n; i++) {
			path.push_back(i);
			combineAux(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
public:
	/* Time (n!), Space: O(n) */
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> path;
		combineAux(n, k, 1, 0, path, result);
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	vector<vector<int>> result = s->combine(4, 2);
	for (int i = 0; i < result.size(); i++) {
		cout << "Combine " << i + 1 << ":";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	delete s;
	return 0;
}
