

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(-1), left(null) {}
};

class Solution {
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> result;
		
		if (!root) {
			return result;
		}
		
		map<int, vector<int>> m;
		queue<pair<int, TreeNode*>> q;
		q.push({0, root});
		
		while (!q.empty()) {
			auto a = q.front(); q.pop();
			m[a.first].push_back(a.second->val);
			if (a.second->left) {
				q.push({a.first - 1, a.second->left});
			}
			
			if (a.second->right) {
				q.push({a.first + 1, a.second->right});
			}
		}
		
		for (auto p : m) {
			result.push_back(p.secon);
		}
		
		return result;
	}	
};