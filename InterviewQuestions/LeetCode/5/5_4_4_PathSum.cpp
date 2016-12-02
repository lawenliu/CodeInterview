/*****************************************************
* Given a binary tree and a sum, find all root-to leaf paths where each path's sum
* equals the given sum.
* For example: Given the below binary tree and sum = 22.
*           5
*          / \
*         4   8
*        /   / \
*       11  13  4
*      /  \      \
*     7    2      1
* return
*  [
*  		[5, 4, 11, 2],
* 		[5, 8, 4, 5]
*  ]
*****************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	/* Time: O(n), Space: O(logn) */
	void pathSumAux(TreeNode* root, int gap, vector<int> &path, vector<vector<int>> &result) {
		if (root == nullptr) {
			return;
		}
		
		path.push_back(root->val);
		gap = gap - root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (gap == 0) {
				result.push_back(path);
			}
		}
		pathSumAux(root->left, gap, path, result);
		pathSumAux(root->right, gap, path, result);
		path.pop_back();
	}
public:
	/* Time: O(n), Space: O(1) */
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;
		
		pathSumAux(root, sum, path, result);
		
		return result;
	}
	
	/* {1, #, 2, 3} for 
		1
		 \
		  2
		 /
		3
		{3, 9, 20, #, #, 15, 7} for 
		      3
				 / \
				9   20
			     /  \
					15   7
	*/
	void createFakeTree(vector<TreeNode*> level, vector<string> values) {		
		vector<TreeNode*> newLevel;
		for (int i = 0; i < level.size(); i++) {
			TreeNode* node = level[i];
			if (values.empty() || values[0] == "#") {
				node->left = nullptr;
			} else {
				size_t i;
				node->left = new TreeNode(stoi(values[0], &i));
				newLevel.push_back(node->left);
			}
			
			if (!values.empty()) {
				values.erase(values.begin());
			}			
			
			if (values.empty() || values[0] == "#") {
				node->right = nullptr;
			} else {
				size_t i;
				node->right = new TreeNode(stoi(values[0], &i));
				newLevel.push_back(node->right);
			}
			
			if (!values.empty()) {
				values.erase(values.begin());
			}
		}
		
		if (!newLevel.empty()) {
			createFakeTree(newLevel, values);
		}
	}
	
	void outputTree(TreeNode* root) {
		queue<TreeNode*> cur, next;
		
		if (root != nullptr) {
			cur.push(root);
		}
		
		while (!cur.empty()) {
			while (!cur.empty()) {
				TreeNode* node = cur.front();
				cur.pop();
				cout << node->val << "(";
				if (node->left != nullptr) {
					next.push(node->left);
					cout << "/";
				}
				
				if (node->right != nullptr) {
					next.push(node->right);
					cout << "\\";			}
				
				cout << ") ";
			}
			
			cout << endl;
			swap(next, cur);
		}
	}
	
	void deleteTree(TreeNode* root) {
		if (root != nullptr) {
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<string> values;
	values.push_back("5");
	values.push_back("4");
	values.push_back("8");
	values.push_back("11");
	values.push_back("#");	
	values.push_back("13");
	values.push_back("4");
	values.push_back("7");
	values.push_back("2");
	values.push_back("#");
	values.push_back("#");
	values.push_back("5");
	values.push_back("1");
	
	vector<TreeNode*> level;
	size_t i;
	TreeNode* root = new TreeNode(stoi(values[0], &i));
	values.erase(values.begin());
	level.push_back(root);
	cout << "Initialize tree finished!" << endl;
	s->createFakeTree(level, values);
	cout << "Create tree finished!" << endl;
	vector<vector<int>> result = s->pathSum(root, 22);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "path " << i + 1 << ": ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}