/*************************************************
* Given a binary tree, find the maximum path sum.
* The path may start and end at any node in the tree.
* For example: Given the below binary tree,
*     1
*    / \
*   2   3
* return 6.
*************************************************/
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
	int maxPathSumAux(TreeNode* root, int &maxSum) {
		if (root == nullptr) {
			return 0;
		}
		
		int left = maxPathSumAux(root->left, maxSum);
		int right = maxPathSumAux(root->right, maxSum);
		int sum = root->val;
		if (left > 0) {
			sum += left;
		}
		
		if (right > 0) {
			sum += right;
		}
		
		maxSum = max(sum, maxSum);
		
		return max(left, right) > 0 ? max(left, right) + root->val : root->val;
	}
public:
	/* Time: O(n), Space: O(1) */
	int maxPathSum(TreeNode* root) {
		int maxSum = 0;
		maxPathSumAux(root, maxSum);		
		return maxSum;
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
	cout << "Solution 1: " << s->maxPathSum(root) << endl;	
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}                                                                                 