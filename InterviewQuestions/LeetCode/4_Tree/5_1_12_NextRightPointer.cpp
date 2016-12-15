/*********************************************
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would you prevous solution still work?
* Note: Youmay only use constant space.
* For example, Given the following binary tree,
*          1
*         / \
*        2   3
*       / \   \
*      4   5   7
* After calling your function, the tree should look like:
*           1 -> NULL
*          / \
*         2-> 3 -> NULL
*        / \   \
*       4-> 5-> 7 -> NULL
*********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	void connect1(TreeLinkNode* root) {
		if (root == nullptr) {
			return;
		}
		
		TreeLinkNode dummy(-1);
		TreeLinkNode* cur = root;
		TreeLinkNode* prev = &dummy;
		while (cur != nullptr) {
			if (cur->left != nullptr) {
				prev->next = cur->left;
				prev = prev->next;
			}
			
			if (cur->right != nullptr) {
				prev->next = cur->right;
				prev = prev->next;
			}
			
			cur = cur->next;
		}
		
		connect1(dummy.next);
	}
	
	/* Time: O(n), space: O(1) */
	void connect2(TreeLinkNode* root) {
		TreeLinkNode* firstOfNextLine;
		TreeLinkNode* prev;
		TreeLinkNode* p = root;
		while (p != nullptr) {
			firstOfNextLine = nullptr;
			prev = nullptr;
			while (p != nullptr) {
				if (firstOfNextLine == nullptr) {
					firstOfNextLine = p->left != nullptr ? p->left : p->right;
				}
				
				if (p->left != nullptr) {
					if (prev != nullptr) {
						prev->next = p->left;
					}
					
					prev = p->left;
				}
				
				if (p->right != nullptr) {
					if (prev != nullptr) {
						prev->next = p->right;
					}
					
					prev = p->right;
				}
				
				p = p->next;
			}
			
			p = firstOfNextLine;
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
		queue<TreeLinkNode*> cur, next;
		
		if (root != nullptr) {
			cur.push(root);
		}
		
		while (!cur.empty()) {
			TreeLinkNode* p = cur.front();
			while (p != nullptr) {
				cout << p->val << " ";
				p = p->next;
			}
			
			while (!cur.empty()) {
				TreeLinkNode* node = cur.front();
				cur.pop();
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
	s->connect1(root);
	cout << "Connect finished!" << endl;
	s->outputResult(root);
	
	cout << "Solution 2: " << endl;
	s->connect2(root);
	cout << "Connect finished!" << endl;
	s->outputResult(root);
	
	s->deleteTree(root);
	cout << "Delete tree finished!" << endl;
	
	delete s;
	return 0;
}