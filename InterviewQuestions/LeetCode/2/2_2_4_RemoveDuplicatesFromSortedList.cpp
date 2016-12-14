/**********************************************
* Given a sorted linked list, delete all duplicates such that each element
* appear only once.
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
**********************************************/
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
	ListNode* deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		
		ListNode *p = head->next;
		if (head->val == p->val) {
			while (p != nullptr && head->val == p->val) {
				ListNode *tmp = p;
				p = p->next;
				delete tmp;
			}
			
			head->next = deleteDuplicates(p);
			return head;
		} else {
			head->next = deleteDuplicates(head->next);
			return head;
		}
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
	vector<int> array1 = { 1, 1, 2 };
	vector<int> array2 = { 1, 1, 2, 3, 3 };
	ListNode* head1 = s->generateList(array1);
	ListNode* head2 = s->generateList(array2);
	
	cout << "Case 1:" << endl;
	ListNode* result1 = s->deleteDuplicates(head1);
	s->outputList(result1);
	cout << endl << "Case 2:" << endl;
	ListNode* result2 = s->deleteDuplicates(head2);
	s->outputList(result2);
	
	s->deleteList(result1);
	s->deleteList(result2);
	
	delete s;
	return 0;
}