/*****************************************************************
* Given a linked list and a value x, partition it such that all nodes less
* than x come before nodes greater than or equal to x.
* You should preserve the original relative order of the nodes in each of the two partitions.
* For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
*****************************************************************/
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
	ListNode* partition(ListNode *head, int x) {
		ListNode dummyLeft(-1);
		ListNode dummyRight(-1);
		ListNode *left = &dummyLeft;
		ListNode *right = &dummyRight;
		ListNode *p = head;
		
		while (p != nullptr) {
			if (p->val < x) {
				left->next = p;
				left = left->next;
			} else {
				right->next = p;
				right = right->next;
			}
			
			p = p->next;
		}
		
		right->next = nullptr;
		left->next = dummyRight.next;
		
		return dummyLeft.next;
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
	vector<int> array = { 1, 4, 3, 2, 5, 2 };
	ListNode* head = s->generateList(array);
	cout << "Result:" << endl;
	ListNode* result = s->partition(head, 3);
	s->outputList(result);
	
	s->deleteList(result);
	
	delete s;
	return 0;
}