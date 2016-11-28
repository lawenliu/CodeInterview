/*************************************************
* Given two binary trees, write a function to check if they are equal or not.
* Two binary trees are considered equal if they are structurally identical and
* the nodes have the same value.
*************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(logn) */
	bool isSameTree1(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		} if (p == nullptr || q == nullptr) {
			return false;
		}
		
		return p->val == q->val
						&& isSameTree1(p->left, q->left)
						&& isSameTree1(p->right, q->right);
	}
	
	/* Time: O(n), Space: O(logn) */
	bool isSameTree2(TreeNode* p, TreeNode* q) {
		stack<TreeNode*> stk;
		stk.push(p);
		stk.push(q);
		
		while (!stk.empty()) {
			p = stk.top();
			stk.pop();
			q = stk.top();
			stk.pop();
			
			if (p == nullptr && q == nullptr) {
				continue;
			} else if (p == nullptr || q == nullptr) {
				return false;
			} else if (p->val != q->val) {
			  return false;
			}
			
			stk.push(p->left);
			stk.push(q->left);
			
			stk.push(p->right);
			stk.push(q->right);
		}
		
		return true;
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
	values1.push_back("7");
	values1.push_back("9");
	values1.push_back("15");
	values1.push_back("#");
	values1.push_back("#");
	values1.push_back("3");
	values1.push_back("20");
	vector<string> values2;
	values2.push_back("7");
	values2.push_back("9");
	values2.push_back("15");
	values2.push_back("#");
	values2.push_back("#");
	values2.push_back("3");
	values2.push_back("18");
	
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
	
	cout << "Solution 1: " << s->isSameTree1(root1, root1) << endl;
	cout << "Solution 1: " << s->isSameTree1(root1, root2) << endl;
	cout << "Solution 2: " << s->isSameTree2(root1, root1) << endl;
	cout << "Solution 2: " << s->isSameTree2(root1, root2) << endl;
	cout << "Check finished!" << endl;
	s->deleteTree(root1);
	s->deleteTree(root2);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}
