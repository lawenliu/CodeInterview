/***********************************************
* A linked list is given such that each node contains an additional random
* pointer which could point to any node in the list or null.
* Return a deep copy of the list.
***********************************************/
#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
	int val;
	RandomListNode *next;
	RandomListNode *random;
	RandomListNode(int v) : val(v), next(nullptr), random(nullptr) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	RandomListNode* copyRandomList(RandomListNode *head) {
		// 1. Copy itself
		RandomListNode *cur = head;
		while (cur != nullptr) {
			RandomListNode *node = new RandomListNode(cur->val);
			node->next = cur->next;
			cur->next = node;
			cur = cur->next->next;
		}
		
		// 2. connect the random pointer
		cur = head;
		while (cur != nullptr) {
			if (cur->random != nullptr) {
				cur->next->random = cur->random;
			}
			
			cur = cur->next->next;
		}
		
		// 3. Split
		RandomListNode dummy(-1);
		RandomListNode *newCur = &dummy;
		cur = head;
		while(cur != nullptr) {
			newCur->next = cur->next;
			newCur = newCur->next;
			cur->next = cur->next->next;
			cur = cur->next;
		}
		
		cout << "Test 3" << endl;
		
		return dummy.next;
	}
	
	RandomListNode* generateList(vector<int> array) {
		RandomListNode dummy(-1);
		RandomListNode* cur = &dummy;
		for (int i = 0; i < array.size(); i++) {
			cur->next = new RandomListNode(array[i]);
			cur = cur->next;
		}
		
		return dummy.next;
	}
	
	void outputList(RandomListNode* head) {
		while (head != nullptr) {
			cout << head->val << " ";
			head = head->next;
		}
	}
	
	void deleteList(RandomListNode* head) {
		while (head != nullptr) {
			RandomListNode* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> array = { 1, 2, 3, 4 };
	RandomListNode* head = s->generateList(array);
	RandomListNode* newHead = s->copyRandomList(head);
	s->outputList(newHead);
	s->deleteList(head);
	
	delete s;
	return 0;
}