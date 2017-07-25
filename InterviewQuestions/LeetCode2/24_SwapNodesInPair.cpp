/***********************************************************************
* Given a linked list, swap every two adjacent nodes and return its head.
* For example,
*  Given 1->2->3->4, you should return the list as 2->1->4->3.
* You algorithm should use only constant space. You may not modify the
* values in the list. only nodes itself can be changed.
***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	ListNode* swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		
		ListNode dummy(-1);
		ListNode *prev = &dummy;
		ListNode *cur = head;
		while (cur != nullptr && cur->next != nullptr) {
			ListNode *next = cur->next;
			prev->next = next;
			cur->next = next->next;
			next->next = cur;
			prev = cur;
			cur = cur->next;
		}
		
		return dummy.next;
	}
	
	/* Time: O(n), Space: O(1) */
	ListNode* swapPairs2(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		
		ListNode *next = head->next;
		head->next = swapPairs2(head->next->next);
		next->next = head;
		
		return next;
	}
	
	ListNode* generateList(vector<int> array) {
		ListNode dummy(-1);
		ListNode* cur = &dummy;
		for (int i = 0; i < array.size(); i++) {
			cur->next = new ListNode(array[i]);
			cur = cur->next;
		}
		
		return dummy.next;
	}
	
	void outputList(ListNode* head) {
		while (head != nullptr) {
			cout << head->val << " ";
			head = head->next;
		}
	}
	
	void deleteList(ListNode* head) {
		while (head != nullptr) {
			ListNode* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> array = { 1, 2, 3, 4 };
	ListNode *head = s->generateList(array);
	cout << "Result:" << endl;
	ListNode *result = s->swapPairs2(head);
	s->outputList(result);
	
	s->deleteList(result);
	
	delete s;
	return 0;
}
