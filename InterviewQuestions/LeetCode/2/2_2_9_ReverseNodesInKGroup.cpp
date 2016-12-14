/*********************************************************
* Given a lined list, reverse the nodes of a linked list k at a time
* and return its modified list.
* If the number of nodes is not a multiple of k then left-out nodes
* in the end should remain as it is.
* You may not alter the values in the nodes, only nodes itself may be changed.
* Only constant memory is allowed.
* For example, Given this linked list: 1->2->3->4->5
* For k = 2, you should return: 2->1->4->3->5
* For k = 3, you should return: 3->2->1->4->5
*********************************************************/
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
	ListNode* reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) {
			return head;
		}
		
		ListNode *nextGroup = head;
		for (int i = 0; i < k; i++) {
			if (nextGroup != nullptr) {
				nextGroup = nextGroup->next;
			} else {
				return head;
			}
		}
		
		ListNode *newNextGroup = reverseKGroup(nextGroup, k);
		ListNode *prev = nullptr;
		ListNode *cur = head;
		while (cur != nextGroup) {
			ListNode *next = cur->next;
			if (prev == nullptr) {
				cur->next = newNextGroup;
			} else {
				cur->next = prev;
			}
			
			prev = cur;
			cur = next;
		}
		
		return prev;
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
	ListNode* head1 = s->generateList(array);
	ListNode *head2 = s->generateList(array);
	cout << "K = 2:" << endl;
	ListNode* result1 = s->reverseKGroup(head1, 2);
	s->outputList(result1);
	cout << endl << "K = 3:" << endl;
	ListNode* result2 = s->reverseKGroup(head2, 3);
	s->outputList(result2);
	
	s->deleteList(result1);
	s->deleteList(result2);
	
	delete s;
	return 0;
}