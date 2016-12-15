/****************************************
* Given two sorted integer arrays A and B, merge B into A
* as one sorted array.
* Note: You may assume that A has enough space to hold additional
* elements from B. The number of elements initialized in A and B
* are m and n respectively.
****************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(m + n), Space: O(1) */
	void merge(vector<int> &A, int m, vector<int> &B, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (A[i] > B[j]) {
				A[k--] = A[i--];
			} else {
				A[k--] = B[j--];
			}
		}
		
		while (j >= 0) {
			A[k--] = B[j--];
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A = { 1, 3, 5, 7, 9, 0, 0, 0, 0, 0 };
	vector<int> B = { 2, 4, 6, 8, 10 };
	
	s->merge(A, 5, B, 5);
	
	cout << "Solution 1: " << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	
	delete s;	
	return 0;
}