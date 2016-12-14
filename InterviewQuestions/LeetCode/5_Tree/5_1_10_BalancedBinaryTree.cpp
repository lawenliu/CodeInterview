/*********************************************************
* Given a binary tree, determine if it is height-balanced.
* For this problem, a height -balanced binary tree is defined as a binary tree
* in which the depth of the two subsets of every node never differ by more than 1.
*********************************************************/
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
	int balancedHeight(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		
		int leftHeight = balancedHeight(root->left);
		int rightHeight = balancedHeight(root->right);
		if (leftHeight < 0 || rightHeight < 0 || abs(leftHeight - rightHeight) > 1) {
			return -1;
		}
		
		return max(leftHeight, rightHeight) + 1;
	}
public:
	/* Time: O(n), Space: O(logn) */
	bool isBalanced(TreeNode* root) {
		return (balancedHeight(root) >= 0);
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
	values1.push_back("1");
	values1.push_back("2");
	values1.push_back("2");
	values1.push_back("#");
	values1.push_back("3");
	values1.push_back("#");
	values1.push_back("3");
	vector<string> values2;
	values2.push_back("1");
	values2.push_back("#");
	values2.push_back("5");
	values2.push_back("#");
	values2.push_back("6");
	
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
	
	cout << "Solution 1: " << s->isBalanced(root1) << endl;
	cout << "Solution 1: " << s->isBalanced(root2) << endl;
	cout << "Check finished!" << endl;
	s->deleteTree(root1);
	s->deleteTree(root2);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}