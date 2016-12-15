/**********************************************
* Merge two sorted linked lists and return it as a new list. The new list should
* be made by splicing together the nodes of the first two lists.
**********************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
	/* Time: O(m + n), Space: O(1) */
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
		
		p->next = l1 != nullptr ? l1 : l2;
		return dummy.next;
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
	
	void outputResult(ListNode* l) {
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
};

int main(void) {
	Solution* s = new Solution();
	vector<int> arr1 = { 1, 3, 5, 7, 9 };
	vector<int> arr2 = { 2, 4, 6, 8, 10 };
	
	ListNode* l1 = s->createList(arr1);
	ListNode* l2 = s->createList(arr2);
	cout << "Data 1:" << endl;
	s->outputResult(l1);
	cout << "Data 2:" << endl;
	s->outputResult(l2);
	ListNode* result = s->mergeTwoLists(l1, l2);
	
	cout << "Solution 1:" << endl;
	s->outputResult(result);
	s->deleteList(result);
	
	delete s;
	return 0;
}