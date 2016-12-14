/****************************************************
* Given preorder and inorder traversal of a tree, construct the binary tree.
* Note You may assume that duplicates do not exist in the tree.
****************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(logn) */
	TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() == 0 || inorder.size() == 0) {
			return nullptr;
		}
		
		int value = preorder[0];
		auto inPos = find(inorder.begin(), inorder.end(), value);
		preorder.erase(preorder.begin());
		TreeNode* node = new TreeNode(value);
		vector<int> leftInVec(inorder.begin(), inPos);
		vector<int> rightInVec(inPos + 1, inorder.end());
		node->left = buildTree(preorder, leftInVec);
		node->right = buildTree(preorder, rightInVec);
		
		return node;
	}
	
	void outputResult(TreeNode* root) {
		queue<TreeNode*> cur, next;
		
		if (root != nullptr) {
			cur.push(root);
		}
		
		while (!cur.empty()) {
			while (!cur.empty()) {
				TreeNode* node = cur.front();
				cur.pop();
				cout << node->val << " ";
				if (node->left != nullptr) {
					next.push(node->left);
				}
				
				if (node->right != nullptr) {
					next.push(node->right);
				}
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
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(6);
	
	cout << "Solution 1: " << endl;
	TreeNode* root = s->buildTree(preorder, inorder);
	cout << "Flatten finished!" << endl;
	s->outputResult(root);
	
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}