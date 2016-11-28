/******************************************
* Sort a linked list using insertion sort.
******************************************/
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
	ListNode* findInsertPosition(ListNode* head, int key) {
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur != nullptr && cur->val < key) {
			prev = cur;
			cur = cur->next;
		}
		
		return prev;
	}
public:
	/* Time: O(n^2), Space: O(1) */
	ListNode* insertionSort(ListNode* head) {
		ListNode dummy(INT_MIN);
		ListNode *p = head;
		while (p != nullptr) {
			ListNode* position = findInsertPosition(&dummy, p->val);
			ListNode* tmp = p->next;
			p->next = position->next;
			position->next = p;
			
			p = tmp;
		}
		
		return dummy.next;
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
	ListNode* result = s->insertionSort(list);
	
	cout << "Solution 1:" << endl;
	s->outputResult(result);
	s->deleteList(result);
	
	delete s;
	return 0;
}