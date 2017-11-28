/**************************************************
* Given an array of number, calculate the distance of BST of this array
* Such as [5,6,3,1,2,4]
**************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct BstNode {
	int val;
	BstNode *left;
	BstNode *right;
	BstNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	BstNode* createBst(vector<int> values) {
		BstNode *root = nullptr;
		if (values.size() > 0) {
			root = new BstNode(values[0]);
		}
		
		for (int i = 1; i < values.size(); i++) {
			addValue(root, values[i]);
		}
		
		return root;
	}
	
	void addValue(BstNode* node, int value) {
		if (node->val > value) {
		    if (node->left == nullptr) {
				node->left = new BstNode(value);
				return;
			} else {
				addValue(node->left, value);
			}
		} else {
			if (node->right == nullptr) {
				node->right = new BstNode(value);
				return;
			} else {
				addValue(node->right, value);
			}
		}
	}
	
	BstNode* findLCA(BstNode *node, int node1, int node2) {
		if (node->val >= node1 && node->val <= node2) {
			return node;
		} else if (node->val > node1 && node->val > node2) {
			return findLCA(node->left, node1, node2);
		} else {
			return findLCA(node->right, node1, node2);
		}
	}
	
	int calculateLen(BstNode *node, int value) {
		if (node == nullptr) {
			return -1;
		}
		
		int res = 0;
		if (node->val > value) {
			res = calculateLen(node->left, value);
		} else if(node->val < value) {
			res = calculateLen(node->right, value);
		} else {
			res = 0;
		}
		
		return res == -1 ? res : res + 1;
	}
public:
	int bstDistance(vector<int> values, int node1, int node2) {
		BstNode *root = createBst(values);
		if (node1 > node2) {
			node1 += node2;
			node2 = node1 - node2;
			node1 = node1 - node2;
		}
		
		BstNode *lca = findLCA(root, node1, node2);
		int leftLen = calculateLen(lca, node1);
		int rightLen = calculateLen(lca, node2);
		if (leftLen == -1 || rightLen == -1) {
			return -1;
		} else {
			return leftLen + rightLen - 2;
		}
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> values = {5,6,3,1,2,4};
	cout << "result: " << s->bstDistance(values, 5, 5) << endl;
	
	delete s;
	return 0;
}