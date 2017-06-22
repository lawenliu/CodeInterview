/********************************************************
* Two elements of a binary search tree (BST) are swapped by mistake.
* Recover the tree without changing its structure.
* Note: A solution using O(n) space is pretty straignt forward. Could you devise a constant
* space solution?
********************************************************/
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
	void checkBroken(TreeNode* prev, TreeNode* cur, pair<TreeNode*, TreeNode*> &brokenPair) {
		if (prev != nullptr && prev->val > cur->val) {
			if (brokenPair.first == nullptr) {
				brokenPair.first = prev;
			}
			
			brokenPair.second = cur;
		}
	}
public:
	/* Morris: Time: O(n), Space: O(1) */
	void recoverTree(TreeNode* root) {
		pair<TreeNode*, TreeNode*> brokenPair;
		TreeNode* prev = nullptr;
		TreeNode* cur = root;
		
		while (cur != nullptr) {
			if (cur->left == nullptr) {
				checkBroken(prev, cur, brokenPair);
				prev = cur;
				cur = cur->right;
			} else {
				TreeNode* node = cur->left;
				while (node->right != nullptr && node->right != cur) {
					node = node->right;
				}
				
				if (node->right == nullptr) {
					node->right = cur;
					cur = cur->left;
				} else {
					checkBroken(prev, cur, brokenPair);
					node->right = nullptr;
					prev = cur;
					cur = cur->right;
				}
			}
		}
		
		swap(brokenPair.first->val, brokenPair.second->val);
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
};


int main(void) {
	Solution* s = new Solution();
	vector<string> values;
	values.push_back("7");
	values.push_back("9");
	values.push_back("15");
	values.push_back("#");
	values.push_back("#");
	values.push_back("3");
	values.push_back("20");
	
	vector<TreeNode*> level;
	size_t i;
	TreeNode* root = new TreeNode(stoi(values[0], &i));
	values.erase(values.begin());
	level.push_back(root);
	cout << "Initialize tree finished!" << endl;
	s->createFakeTree(level, values);
	cout << "Create tree finished!" << endl;
	
	cout << "Solution 1: " << endl;
	s->recoverTree(root);
	cout << "Recover finished!" << endl;
	s->outputResult(root);
	
	cout << "Ouput finsihed!" << endl;
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}