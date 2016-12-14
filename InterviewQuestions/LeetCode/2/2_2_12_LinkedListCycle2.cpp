/***************************************************
* Given a linked list, return the node where the cycle begins. If there
* is no cycle, return null.
* Follow up: Can you solve it without using extra space?
***************************************************/
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
	ListNode* detectCycle(ListNode *head， int k) {
		if (head == nullptr || head->next == nullptr) {
			return nullptr;
		}
		
		ListNode *slow, *fast;
		slow = head;
		fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				ListNode* slow2 = head;
				while (slow2 != slow) {
					slow = slow->next;
					slow2 = slow2->next;
				}
				
				return slow;
			}
		}
		return nullptr;
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
	ListNode* result = s->detectCycle(head);
	if (result == nullptr) {
		cout << "No cycle!" << endl;
	} else {
		cout << result->val << endl;
	}
	
	ListNode* cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	
	cur->next = head;
	result = s->detectCycle(head);
	if (result == nullptr) {
		cout << "No cycle!" << endl;
	} else {
		cout << result->val << endl;
	}
	
	cur->next = nullptr;
	s->deleteList(head);
	
	delete s;
	return 0;
}