/************************************************************************
* Given a linked list, remove the nth node from the end of list and return its head.
* For example:
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.
************************************************************************/
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
	ListNode* generateList(vector<int> array) {
		ListNode dummy(-1);
		ListNode* cur = &dummy;
		for (int i = 0; i < array.size(); i++) {
			cur->next = new ListNode(array[i]);
			cur = cur->next;
		}
		
		return dummy.next;
	}
	
	void outputList(ListNode *head) {
		while (head != nullptr) {
			cout << head->val << " ";
			head = head->next;
		}
	}
	
	void deleteList(ListNode *head) {
		while (head != nullptr) {
			ListNode *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	/* Time: O(n), Space: O(1) */
	ListNode* removeNthFromEnd(ListNode *head, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy, *q = &dummy;
		for (int i = 0; i < n; i++) {
			p = p->next;
		}
		
		while (p->next != nullptr) {
			p = p->next;
			q = q->next;
		}
		
		ListNode *tmp = q->next;
		q->next = q->next->next;
		delete tmp;
		
		return dummy.next;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<int> array = { 1, 2, 3, 4, 5 };
	ListNode *head = s->generateList(array);
	
	cout << "Original List: " << endl;
	s->outputList(head);
	
	ListNode *result = s->removeNthFromEnd(head, 2);
	cout << endl << "Result: " << endl;
	s->outputList(result);
	
	s->deleteList(head);
	
	delete s;
	return 0;
}
