/************************************************
* Given a binary tree containing digits from 0-9 only, each root-to leaf path
* could represent a number.
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
* Find the total sum of all root-to-leaf numbers.
* For example,
*    1
*   / \
*  2   3
* The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path
* 1->3 represents the number 13.
* Return the sum = 12 + 13 = 25.
************************************************/
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
	int sumNumberAux(TreeNode* root, int sum) {
		if (root == nullptr) {
			return 0;
		}
		
		if (root->left == nullptr && root->right == nullptr) {
			return sum * 10 + root->val;
		}
		
		return sumNumberAux(root->left, sum * 10 + root->val)
				+ sumNumberAux(root->right, sum * 10 + root->val);
	}
public:
	/* Time: O(n), Space: O(1) */
	int sumNumber(TreeNode* root) {
		return sumNumberAux(root, 0);
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
	cout << "Solution 1: " << s->sumNumber(root) << endl;	
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}     