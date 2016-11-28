/***********************************************
* Given a binary tree, determine if it is a valid binary search tree (BST).
* Assume a BST is defined as follows:
* 1. The left subtree of a node contains only nodes with keys less than the node's key.
* 2. The right subtree of a node contains only nodes with keys greater than the node's key.
* 3. Both the left and right subtrees must also be binary search trees.
***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	bool isValidBSTAux(TreeNode* root, int lower, int upper) {
		if (root == nullptr) {
			return true;
		}
		
		return (root->val > lower && root->val < upper)
							&& isValidBSTAux(root->left, lower, root->val)
							&& isValidBSTAux(root->right, root->val, upper);
	}
public:
	/* Time: O(n), Space: O(logn) */
	bool isValidBST(TreeNode* root) {
		return isValidBSTAux(root, INT_MIN, INT_MAX);
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
};

int main(void) {
	Solution* s = new Solution();
	vector<string> values1;
	values1.push_back("5");
	values1.push_back("2");
	values1.push_back("#");
	values1.push_back("#");
	values1.push_back("4");
	values1.push_back("3");
	values1.push_back("#");
	vector<string> values2;
	values2.push_back("4");
	values2.push_back("2");
	values2.push_back("6");
	values2.push_back("3");
	values2.push_back("1");
	values2.push_back("5");
	values2.push_back("7");	
	
	vector<TreeNode*> level1, level2;
	size_t i;
	TreeNode* root1 = new TreeNode(stoi(values1[0], &i));
	TreeNode* root2 = new TreeNode(stoi(values2[0], &i));
	values1.erase(values1.begin());
	values2.erase(values2.begin());
	level1.push_back(root1);
	level2.push_back(root2);
	cout << "Initialize tree finished!" << endl;
	s->createFakeTree(level1, values1);
	s->createFakeTree(level2, values2);
	cout << "Create tree finished!" << endl;
	
	cout << "Solution 1: " << s->isValidBST(root1) << endl;
	cout << "Solution 1: " << s->isValidBST(root2) << endl;
	cout << "Check finished!" << endl;
	s->deleteTree(root1);
	s->deleteTree(root2);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}