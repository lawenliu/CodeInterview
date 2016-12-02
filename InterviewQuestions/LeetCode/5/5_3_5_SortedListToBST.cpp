/*************************************
* Given a singly linked list where elements are sorted in ascending order,
* covert it to a height balanced BST.
*************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	int listLength(ListNode* node) {
		int len = 0;
		while (node != nullptr) {
			len++;
			node = node->next;
		}
		
		return len;
	}
	
	ListNode* nextNthNode(ListNode* node, int n) {
		while (n > 1) {
			node = node -> next;
			n--;
		}
		
		return node;
	}
	
	TreeNode* sortedListToBST1Aux(ListNode* head, int len) {
		if (len == 0 || head == nullptr) {
			return nullptr;
		}
		
		TreeNode* root = new TreeNode(nextNthNode(head, len / 2 + 1)->val);
		root->left = sortedListToBST1Aux(head, len / 2);
		root->right = sortedListToBST1Aux(nextNthNode(head, len / 2 + 2), (len - 1) / 2);
		
		return root;
	}
	
	TreeNode* sortedListToBST2Aux(ListNode* &head, int first, int last) {
		if (first > last) {
			return nullptr;
		}
		
		int mid = (first + last) / 2;
		TreeNode* leftChild = sortedListToBST2Aux(head, first, mid - 1);
		TreeNode* root = new TreeNode(head->val);
		root->left = leftChild;
		head = head->next;
		root->right = sortedListToBST2Aux(head, mid + 1, last);
		return root;
	}
public:
	/* Time: O(n^2), Space: O(logn) */
	TreeNode* sortedListToBST1(ListNode* head) {
		return sortedListToBST1Aux(head, listLength(head));
	}
	
	/* Time: O(n), Space: O(logn) */
	TreeNode* sortedListToBST2(ListNode* head) {
		return sortedListToBST2Aux(head, 0, listLength(head) - 1);
	}
	
	ListNode* createList(vector<int> arr) {
		ListNode dummy(-1);
		ListNode* p = &dummy;
		for (int i = 0; i < arr.size(); i++) {
			p->next = new ListNode(arr[i]);
			p = p->next;
		}
		
		return dummy.next;
	}
	
	void outputList(ListNode* l) {
		while (l != nullptr) {
			cout << l->val << " ";
			l = l->next;
		}
		
		cout << endl;
	}
	
	void deleteList(ListNode* l) {
		while (l != nullptr) {
			ListNode* tmp = l;
			l = l->next;
			delete tmp;
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
	vector<int> array = { 1, 3, 5, 7, 9 };
	
	ListNode* list = s->createList(array);
	cout << "Data 1:" << endl;
	s->outputList(list);
	
	TreeNode* result = s->sortedListToBST1(list);
	cout << "Solution 1:" << endl;
	s->outputTree(result);
	s->deleteTree(result);
	
	result = s->sortedListToBST2(list);
	cout << "Solution 2:" << endl;
	s->outputTree(result);
	s->deleteTree(result);
	
	s->deleteList(list);
	
	delete s;
	return 0;
}