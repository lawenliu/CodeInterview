/***************************************
* Merge k sorted linked lists and return it as one sorted list.
* Analyze and describe its complexity.
***************************************/
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		}
		
		if (l2 == nullptr) {
			return l1;
		}
		
		ListNode dummy(-1);
		ListNode *p = &dummy;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			
			p = p->next;
		}
		
		p->next = l1 != nullptr ? l1 : l2;
		return dummy.next;
	}
public:
	/* Time: O(n1 + n2 + n3 + ...), Space: O(1) */
	ListNode* mergeKLists(vector<ListNode*> lists) {
		if (lists.size() == 0) {
			return nullptr;
		}
		
		ListNode* p = lists[0];
		for (int i = 1; i < lists.size(); i++) {
			p = mergeTwoLists(p, lists[i]);
		}
		
		return p;
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
	vector<int> arr1 = { 1, 4, 7, 10 };
	vector<int> arr2 = { 2, 5, 8, 11 };
	vector<int> arr3 = { 3, 6, 9, 12 };	
	ListNode* l1 = s->createList(arr1);
	ListNode* l2 = s->createList(arr2);
	ListNode* l3 = s->createList(arr3);
	vector<ListNode*> lists = { l1, l2, l3 };
	ListNode* result = s->mergeKLists(lists);
	
	cout << "Solution 1:" << endl;
	s->outputResult(result);
	s->deleteList(result);
	
	delete s;
	return 0;
}