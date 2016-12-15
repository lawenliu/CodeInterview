/**********************************************
* Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie. from left
* to right, level by level).
* For example: Given binary tree {3, 9, 20, #, #, 15, 7},
*             3
*            / \
*           9   20
*              /  \
*             15   7
* return its zigzag level order traversal as:
*       [
*           [3]
*           [20, 9]
*           [15, 7]
*       ]
**********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	void zigzagLevelOrder1Aux(TreeNode* root, int level, bool leftToRight, vector<vector<int>> &result) {
		if (root == nullptr) {
			return;
		}
		
		if (level > result.size()) {
			result.push_back(vector<int>());
		}
		
		if (leftToRight) {
			result[level-1].push_back(root->val);
		} else {
			result[level-1].insert(result[level-1].begin(), root->val);
		}
		
		zigzagLevelOrder1Aux(root->left, level + 1, !leftToRight, result);
		zigzagLevelOrder1Aux(root->right, level + 1, !leftToRight, result);
	}
public:
	/* Time: O(n), Space: O(1) */
	vector<vector<int>> zigzagLevelOrder1(TreeNode* root) {
		vector<vector<int>> result;
		zigzagLevelOrder1Aux(root, 1, true, result);
		return result;
	}
	
	/* Time: O(n), Space: O(n) */
	vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
		vector<vector<int>> result;
		queue<TreeNode*> cur, next;
		bool leftToRight = true;
		
		if (root != nullptr) {
			cur.push(root);
		}
		
		while (!cur.empty()) {
			vector<int> level;
			while (!cur.empty()) {
				TreeNode* node = cur.front();
				cur.pop();
				level.push_back(node->val);
				if (node->left != nullptr) {
					next.push(node->left);
				}
				
				if (node->right != nullptr) {
					next.push(node->right);
				}
			}
			
			if(!leftToRight) {
				reverse(level.begin(), level.end());
			}
			
			result.push_back(level);
			leftToRight = !leftToRight;
			swap(next, cur);
		}
		
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
	
	void deleteTree(TreeNode* root) {
		if (root != nullptr) {
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
	}
	
	void outputResult(vector<vector<int>> result) {
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j] << " ";
			}
			
			cout << endl;
		}
	}
};


int main(void) {
	Solution* s = new Solution();
	vector<string> values;
	values.push_back("3");
	values.push_back("9");
	values.push_back("20");
	values.push_back("#");
	values.push_back("#");
	values.push_back("15");
	values.push_back("7");
	
	vector<TreeNode*> level;
	size_t i;
	TreeNode* root = new TreeNode(stoi(values[0], &i));
	values.erase(values.begin());
	level.push_back(root);
	cout << "Initialize tree finished!" << endl;
	s->createFakeTree(level, values);
	cout << "Create tree finished!" << endl;
	
	cout << "Solution 1: " << endl;
	vector<vector<int>> result = s->zigzagLevelOrder1(root);
	cout << "Traverse finished!" << endl;
	s->outputResult(result);
	
	cout << "Solution 2: " << endl;
	result = s->zigzagLevelOrder2(root);
	cout << "Traverse finished!" << endl;
	s->outputResult(result);
	
	cout << "Ouput finsihed!" << endl;
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}