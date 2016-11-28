/*************************************************************
* Given a binary tree
* struct TreeLinkNode {
*   int val;
*   TreeLinkNode *left, *right, *next;
*   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}	
* };
* Populate each next pointer to point to its next right node. If there is no next node, the 
* next pointer should be set to NULL.
* Initially, all next pointers are set to NULL.
* Note:
* 1. You may only use constant extra space.
* 2. You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
*    and every parent has two children).
* For example, Given the following perfect binary tree,
*                1
*               / \
*             2     3
*            / \   / \
*           4   5 6   7
* After calling your function, the tree should look like:
*                1 -> NULL
*               / \
*             2  -> 3 -> NULL
*            / \   / \
*           4-> 5->6->7 -> NULL
*************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
private:
	void connectAux(TreeLinkNode* node, TreeLinkNode* sibling) {
		if (node == nullptr) {
			return;
		} else {
			node->next = sibling;
		}
		
		connectAux(node->left, node->right);
		if (sibling != nullptr) {
			connectAux(node->right, sibling->left);
		} else {
			connectAux(node->right, nullptr);
		}
	}
public:
	/* Time: O(n), Space: O(logn) */
	void connect(TreeLinkNode* root) {
		if (root == nullptr) {
			return;
		}
		
		connectAux(root, nullptr);
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
	void createFakeTree(vector<TreeLinkNode*> level, vector<string> values) {		
		vector<TreeLinkNode*> newLevel;
		for (int i = 0; i < level.size(); i++) {
			TreeLinkNode* node = level[i];
			if (values.empty() || values[0] == "#") {
				node->left = nullptr;
			} else {
				size_t i;
				node->left = new TreeLinkNode(stoi(values[0], &i));
				newLevel.push_back(node->left);
			}
			
			if (!values.empty()) {
				values.erase(values.begin());
			}			
			
			if (values.empty() || values[0] == "#") {
				node->right = nullptr;
			} else {
				size_t i;
				node->right = new TreeLinkNode(stoi(values[0], &i));
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
	
	void outputResult(TreeLinkNode* root) {
		if (root == nullptr) {
			return;
		}
		
		TreeLinkNode* p = root;
		while (p != nullptr) {
			cout << p->val << " ";
			p = p->next;
		}
		
		cout << endl;
		outputResult(root->left);
	}
	
	void deleteTree(TreeLinkNode* root) {
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
	values.push_back("1");
	values.push_back("2");
	values.push_back("3");
	values.push_back("4");
	values.push_back("5");
	values.push_back("6");
	values.push_back("7");
	
	vector<TreeLinkNode*> level;
	size_t i;
	TreeLinkNode* root = new TreeLinkNode(stoi(values[0], &i));
	values.erase(values.begin());
	level.push_back(root);
	cout << "Initialize tree finished!" << endl;
	s->createFakeTree(level, values);
	cout << "Create tree finished!" << endl;
	
	cout << "Solution 1: " << endl;
	s->connect(root);
	cout << "Connect finished!" << endl;
	s->outputResult(root);
	
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}