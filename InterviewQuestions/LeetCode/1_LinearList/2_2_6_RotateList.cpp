/*******************************************************
* Given a list, rotate the list to the right by k places, where k is non-negative.
* For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
*******************************************************/
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
	ListNode* rotateRight(ListNode *head, int k) {
		ListNode *p = head;
		int len = 1;
		while(p->next != nullptr) {
			p = p->next;
			len++;
		}
		
		int n = len - k % len;
		p->next = head;
		
		for (int i = 0; i < n; i++) {
			p = p->next;
		}
		
		head = p->next;
		p->next = nullptr;
		return head;
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
	Solution* s = new Solution();
	vector<int> array = { 1, 2, 3, 4, 5 };
	ListNode* head = s->generateList(array);
	cout << "Result:" << endl;
	ListNode* result = s->rotateRight(head, 2);
	s->outputList(result);
	
	s->deleteList(result);
	
	delete s;
	return 0;
}