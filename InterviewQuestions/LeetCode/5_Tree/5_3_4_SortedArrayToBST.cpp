/***********************************************************
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
***********************************************************/
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
	TreeNode* sortedArrayToBSTAux(vector<int> &nums, int first, int last) {
		if (first > last) {
			return nullptr;
		}
		
		int mid = (first + last) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTAux(nums, first, mid - 1);
		root->right = sortedArrayToBSTAux(nums, mid + 1, last);
		
		return root;
	}
public:
	/* Time: O(n), Space(1) */
	TreeNode* sortedArrayToBST(vector<int> &nums) {
		return sortedArrayToBSTAux(nums, 0, nums.size() - 1);
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
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	TreeNode* result = s->sortedArrayToBST(nums);
	
	cout << "Tree: " << endl;
	s->outputTree(result);
	s->deleteTree(result);
	
	delete s;
	return 0;
}
