/************************************************
* Given a binary tree, flatten it to a linked list in-place.
* For example, Given
*         1
*        / \
*       2   5
*      / \   \
*     3   4   6
* The flattened tree should look like:
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
************************************************/
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
	void flatten1(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		
		flatten1(root->left);
		flatten1(root->right);
		
		if (root->left == nullptr) {
			return;
		}
		
		TreeNode* p = root->left;
		while (p->right != nullptr) {
			p = p->right;
		}
		
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
	
	/* Time: O(n), Space: O(logn) */
	void flatten2(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		
		stack<TreeNode*> stk;
		stk.push(root);
		
		while (!stk.empty()) {
			TreeNode* p = stk.top();
			stk.pop();
			
			if (p->right != nullptr) {
				stk.push(p->right);
			}
			
			if (p->left != nullptr) {
				stk.push(p->left);
			}
			
			p->left = nullptr;
			if (!stk.empty()) {
				p->right = stk.top();
			}
		}
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
	vector<string> values1;
	values1.push_back("1");
	values1.push_back("2");
	values1.push_back("2");
	values1.push_back("3");
	values1.push_back("4");
	values1.push_back("4");
	values1.push_back("3");
	vector<string> values2;
	values2.push_back("1");
	values2.push_back("2");
	values2.push_back("5");
	values2.push_back("3`");
	values2.push_back("4");
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
	
	cout << "Solution 1: " << endl;
	s->flatten1(root1);
	cout << "Flatten finished!" << endl;
	s->outputResult(root1);
	cout << "Solution 1: " << endl;
	s->flatten1(root2);
	cout << "Flatten finished!" << endl;
	s->outputResult(root2);
	
	cout << "Solution 2: " << endl;
	s->flatten2(root1);
	cout << "Flatten finished!" << endl;
	s->outputResult(root1);
	cout << "Solution 2: " << endl;
	s->flatten2(root2);
	cout << "Flatten finished!" << endl;
	s->outputResult(root2);
	
	s->deleteTree(root1);
	s->deleteTree(root2);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}