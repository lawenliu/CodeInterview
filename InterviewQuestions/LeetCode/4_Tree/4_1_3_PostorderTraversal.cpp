/******************************************
* Given a binary tree, return the postorder traversal of its nodes' values.
* For example: given binary tree {1, #, 2, 3},
*      1
*       \
*        2
*       /
*      3
* return [3, 2, 1].
* Note: Recursive solution is trivial, could you do it iteratively?
******************************************/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	void postorderTraversal1Aux(TreeNode *root, vector<int> &result) {
		if (root != nullptr) {
			postorderTraversal1Aux(root->left, result);
			postorderTraversal1Aux(root->right, result);
			result.push_back(root->val);
		}
	}
	
	void reverse(TreeNode* from, TreeNode* to) {
		TreeNode* x = from;
		TreeNode* y = from->right;
		TreeNode* z;
		while (x != to) {
			z = y->right;
			y->right = x;
			x = y;
			y = z;
		}
	}
	
	void visitReverse(TreeNode* from, TreeNode *to, vector<int> &result) {
		TreeNode* p = to;
		reverse(from, to);
		while(true) {
			result.push_back(p->val);
			if (p == from) {
				break;
			}
			
			p = p->right;
		}
		
		reverse(to, from);
	}
public:
	/* Recursive, Time: O(n), Space: (1) */
	vector<int> postorderTraversal1(TreeNode* root) {
		vector<int> result;
		postorderTraversal1Aux(root, result);
		
		return result;
	}
	
	/* Time: O(n), Space: O(n) */
	vector<int> postorderTraversal2(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode* p = root;
		TreeNode* q = nullptr;
		
		do {
			while (p != nullptr) {
				stk.push(p);
				p = p->left;
			}
			
			q = nullptr;
			while (!stk.empty()) {
				p = stk.top();
				stk.pop();
				if (p->right == q) {
					result.push_back(p->val);
					q = p;
				} else {
					stk.push(p);
					p = p->right;
					break;
				}
				
			}
		} while (!stk.empty());
		
		return result;
	}
	
	/* Morris, Time: O(n), Space: O(1) */
	vector<int> postorderTraversal3(TreeNode* root) {
		vector<int> result;
		TreeNode *dummy = new TreeNode(-1);
		dummy->left = root;
		TreeNode *prev = nullptr;
		TreeNode *cur = dummy;
		while (cur != nullptr) {
			if (cur->left == nullptr) {
				prev = cur;
				cur = cur->right;;
			} else { // setup or deal with previous node line
				TreeNode *node = cur->left;
				while (node->right != nullptr && node->right != cur) {
					node = node->right;
				}
				
				if (node->right == nullptr) { // Set previous node line
					node->right = cur;
					prev = cur;
					cur = cur->left;
				} else { // close previouse node line
					visitReverse(cur->left, prev, result);
					node->right = nullptr;					
					prev = cur;
					cur = cur->right;
				}
			}
		}
		
		delete dummy;
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
	
	void outputResult(vector<int> result) {
		cout << "Ouput: ";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		
		cout << endl;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<string> values;
	values.push_back("1");
	values.push_back("#");
	values.push_back("2");
	values.push_back("3");
	
	vector<TreeNode*> level;
	size_t i;
	TreeNode* root = new TreeNode(stoi(values[0], &i));
	values.erase(values.begin());
	level.push_back(root);
	cout << "Initialize tree finished!" << endl;
	s->createFakeTree(level, values);
	cout << "Create tree finished!" << endl;
	
	cout << "Solution 1: " << endl;
	vector<int> result = s->postorderTraversal1(root);
	cout << "Traverse finished!" << endl;
	s->outputResult(result);
	
	cout << "Solution 2: " << endl;
	result = s->postorderTraversal2(root);
	cout << "Traverse finished!" << endl;
	s->outputResult(result);
	
	cout << "Solution 3: " << endl;
	result = s->postorderTraversal3(root);
	cout << "Traverse finished!" << endl;
	s->outputResult(result);
	
	cout << "Ouput finsihed!" << endl;
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}