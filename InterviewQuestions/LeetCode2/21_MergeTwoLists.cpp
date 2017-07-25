/****************************************************************************
* Merge two sorted linked lists and return it as a new list. The new list should
* be made by splicing together the nodes of the first two lists.
****************************************************************************/
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
		ListNode *cur = &dummy;
		
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
	
	/* Time: O(m+n), Space: O(1) */
	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr) {
			return l2;
		}
		
		if (l2 == nullptr) {
			return l1;
		}
		
		ListNode dummy(-1);
		ListNode *p = &dummy;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			
			p = p->next;
		}
		
		p->next = l1 == nullptr ? l2 : l1;
		
		return dummy.next;
	}
	
	/* Time: O(m+n), Space: O(1) */
	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
		if (!l1 || (l2 && l1->val > l2->val)) swap(l1, l2);
		if (l1) l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
};

int main(void) {
	Solution *s = new Solution();
	//vector<int> array1 = { 1, 3, 5, 7, 9 };
	//vector<int> array2 = { 2, 4, 6, 8, 10 };
	
	vector<int> array1 = { 4, 5 };
	vector<int> array2 = { 1, 2, 3 };
	
	ListNode *l1 = s->generateList(array1);
	ListNode *l2 = s->generateList(array2);
	
	cout << "List 1: " << endl;
	s->outputList(l1);
	cout << endl;
	cout << "List 2: " << endl;
	s->outputList(l2);
	cout << endl;
	
	cout << "Result: " << endl;
	ListNode* result = s->mergeTwoLists2(l2, l1);
	s->outputList(result);
	cout << endl;
	
	s->deleteList(result);
	
	delete s;
	return 0;
}
