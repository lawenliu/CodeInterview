/*********************************************************
* Given a singly linked list L: L0 -> L1 -> ... -> Ln-1 -> Ln, reorder it to:
8 L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
* You must do this in-place without altering the nodes' values.
* For example, Given {1, 2, 3, 4}, reorder it to {1, 4, 2, 3}.
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
private:
	void merge(ListNode* list1, ListNode* list2) {
		ListNode *cur = list1;
		while (cur->next != nullptr) {
			ListNode *tmp = cur->next;
			cur->next = list2;
			list2 = list2->next;
			cur->next->next = tmp;
			cur = tmp;
		}
		
		cur->next = list2;
	}
	
	ListNode* reverse(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		
		ListNode *prev = head;
		ListNode *cur = head->next;
		ListNode *next = cur->next;
		while (cur != nullptr) {
			cur->next = prev;
			prev->next = next;
			prev = cur;
			cur = next;
			next = cur == nullptr ? nullptr : cur->next;
		}
		
		head->next = nullptr;
		return prev;
	}
public:
	/* Time: O(n), Space: O(1) */
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return;
		}
		
		ListNode *slow, *fast, *prev;
		slow = head;
		fast = head;
		prev = nullptr;
		// 1. Find median
		while (fast != nullptr && fast->next != nullptr) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		
		// 2. Split
		prev->next = nullptr;
		// 3. Reverse right half list
		slow = reverse(slow);
		
		// 4. Merge
		merge(head, slow);
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
	vector<int> array = { 1, 2, 3, 4 };
	ListNode* head = s->generateList(array);
	s->reorderList(head);
	s->outputList(head);
	s->deleteList(head);
	
	delete s;
	return 0;
}