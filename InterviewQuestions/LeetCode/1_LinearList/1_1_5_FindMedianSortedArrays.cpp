/********************************************
* There are two sorted arrays A and B of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time
* complexity should be O(log(m + n))
********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(log(m+n)), Space: O(1) */
	double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
		const int m = A.size();
		const int n = B.size();
		int total = m + n;
		if (total % 2 == 1) {
			return findKth(A, 0, B, 0, total / 2 + 1);
		} else {
			return (findKth(A, 0, B, 0, total / 2) + findKth(A, 0, B, 0, total / 2 + 1)) / 2.0;
		}
	}
	
	int findKth(vector<int> va, int i, vector<int> vb, j, int k) {
		if (va.size() - i > vb.size() - j) {
			return findKth(vb, j, va, i, k);
		}
		
		if (va.size() == i) {
			return vb[j+k-1];
		}
		
		if (k == 1) {
			return min(va[i], vb[j]);
		}
		
		int vi = min(i + k / 2, (int)va.size());
		int vj = j + (k - (vi - i));
		if (va[vi-1] < vb[vj-1]) {
			return findKth(va, vi, vb, j, k - (vi - i));
		} else (va[vi-1] > vb[vj-1]) {
			return findKth(vb, i, vb, j, k - (vj - j));
		} else {
			return va[vi -1];
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A = { 1, 3, 5, 7, 9 };
	vector<int> B = { 2, 4, 6, 8 };
	vector<int> C = { 2, 4, 6, 8, 10 };
	
	int result1 = s->findMedianSortedArrays(A, B);
	int result2 = s->findMedianSortedArrays(A, C);
	cout << "Solution 1: " << result1 << endl;
	cout << "Solution 2: " << result2 << endl;
	
	delete s;
	return 0;
}