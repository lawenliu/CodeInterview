/*************************************************************
* You are given two linked lists representing two non-negative
* numbers. The digits are stored in reverse order and each of
* their nodes contain a single digit. Add the two numbers and
* return it as a linked list.
* Input: (2->4->3) + (5->6->4)
* Output: 7->0->8
**************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v): val(v), next(nullptr) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode* pr = &dummy;
		ListNode* pa = l1;
		ListNode* pb = l2;
		int ci = 0;
		while(pa != nullptr || pb != nullptr) {
			int ai = pa == nullptr ? 0 : pa->val;
			int bi = pb == nullptr ? 0 : pb->val;
			int ri = (ai + bi + ci) % 10;
			ci = (ai + bi + ci) / 10;
			pr->next = new ListNode(ri);
			pr = pr->next;
			pa = pa == nullptr ? nullptr : pa->next;
			pb = pb == nullptr ? nullptr : pb->next;
		}
		
		if (ci > 0) {
			pr->next = new ListNode(ci);
		}
		
		return dummy.next;
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
		ListNode* cur = head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
	}
	
	void deleteList(ListNode* head) {
		ListNode* cur = head;
		while (cur != nullptr) {
			ListNode* tmp = cur->next;
			delete cur;
			cur = tmp;
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> array1 = { 2, 4, 5 };
	vector<int> array2 = { 5, 6, 4 };
	ListNode* pa = s->generateList(array1);
	ListNode* pb = s->generateList(array2);
	
	ListNode* pr = s->addTwoNumbers(pa, pb);
	cout << "Result as following: " << endl;
	s->outputList(pr);
	
	s->deleteList(pa);
	s->deleteList(pb);
	s->deleteList(pr);
	
	
	delete s;
	return 0;
}

