/*********************************************************
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* For example: given 1->2->3->4->5->nullptr, m = 2 and n = 4,
* return 1->4->3->2->5->nullptr.
* None: Give m, n satisfy the following condition: 1 <= m <= n <= length of list.
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
	ListNode* reverseBetween(ListNode *head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *prev = &dummy;
		for (int i = 0; i < m - 1; i++) {
			prev = prev->next;
		}
		
		ListNode *headTmp = prev;
		ListNode *cur = prev->next;
		for (int i = m; i < n; i++) {
			ListNode *next = cur->next;
			cur->next = next->next;
			next->next = headTmp->next;
			headTmp->next = next;
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
	ListNode* result = s->reverseBetween(head, 2, 4);
	s->outputList(result);
	
	s->deleteList(result);
	
	delete s;
	return 0;
}