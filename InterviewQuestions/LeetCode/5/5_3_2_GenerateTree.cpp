/*************************************************************
* Given n, generate all structurally unique BST's (binary search trees) that
* store values 1..n. For example, Given n = 3, your program should return all
* 5 unique BST's shown belown.
*        1          3         3        2       1
*         \        /         /        / \       \
*          3      2         1        1   3       2
*         /      /           \                    \
*        2      1             2                    3
*************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	vector<TreeNode*> generateAux(int start, int end) {
		vector<TreeNode*> subtrees;
		if (start > end) {
			subtrees.push_back(nullptr);
			return subtrees;
		}
		
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> leftSubtrees = generateAux(start, i - 1);
			vector<TreeNode*> rightSubtrees = generateAux(i + 1, end);
			for (int j = 0; j < leftSubtrees.size(); j++) {
				for (int k = 0; k < rightSubtrees.size(); k++) {
					TreeNode* node = new TreeNode(i);
					node->left = leftSubtrees[j];
					node->right = rightSubtrees[k];
					subtrees.push_back(node);
				}
			}
		}
		
		return subtrees;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			return generateAux(1, 0);
		} else {
			return generateAux(1, n);
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
	vector<TreeNode*> result = s->generateTrees(3);
	
	for (int i = 0; i < result.size(); i++) {
		cout << "Tree " << i << endl;
		s->outputTree(result[i]);
	}
	
	for (int i = 0; i < result.size(); i++) {
		s->deleteTree(result[i]);
	}
	
	delete s;
	return 0;
}