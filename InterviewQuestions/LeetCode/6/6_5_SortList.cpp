/*****************************************
* Sort a linked list in O(nlogn) time using constant space complexity.
*****************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
private:
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
public:
	/* Time: O(nlogn), Space: O(1) */
	/* Merge-Sort */
	/* T(n) = n / 2 + 2T(n/2) + n, we get (3n/2)logn */
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		
		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p1->next != nullptr && p1->next->next != nullptr) {
			p1 = p1->next->next;
			p2 = p2->next;
		}
		
		p1 = p2;
		p2 = p2->next;
		p1->next = nullptr;
		
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(p2);
		return mergeTwoLists(l1, l2);
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
	vector<int> arr = { 3, 1, 4, 8, 6 };
	
	ListNode* list = s->createList(arr);
	cout << "Data 1:" << endl;
	s->outputResult(list);
	ListNode* result = s->sortList(list);
	
	cout << "Solution 1:" << endl;
	s->outputResult(result);
	s->deleteList(result);
	
	delete s;
	return 0;
}