/*************************************************************
* There are two sorted arrays nums1 and nums2 of size m and n
* respectively. Find the median of the two sorted arrays.
* The overall run time complexity should be O(log(m+n)).
**************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(log(m+n)), Space: O(1) */
	double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
		const int m = A.size();
		const int n = B.size();
		const int total = m + n;
		if (total % 2 == 1) {
			return findKth(A, 0, B, 0, total / 2 + 1);
		} else {
			return (findKth(A, 0, B, 0, total / 2) + findKth(A, 0, B, 0, total / 2 + 1)) / 2.0;
		}
	}
	
private:
	int findKth(vector<int> va, int i, vector<int> vb, int j, int k) {
		if (va.size() - i > vb.size() - j) { // Make sure size of va is less than size of vb.
			return findKth(vb, j, va, i, k);
		}
		
		if (va.size() == i) { // va is used up, try to get the number from vb
			return vb[j+k-1];
		}
		
		if (k == 1) { // only search one more, then get minimum number of va and vb
			return min(va[i], vb[j]);
		}
		
		int vi = min(i + k / 2, (int)va.size()); // get next index of va
		int vj = j + (k - (vi - i)); // get next index of vb
		if (va[vi-1] < vb[vj-1]) {
			return findKth(va, vi, vb, j, k - (vi - i));
		} else if (va[vi-1] > vb[vj-1]) {
			return findKth(va, i, vb, vj, k - (vj - j));
		} else {
			return va[vi-1];
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A = { 2, 4, 6, 8, 10 };
	vector<int> B = { 1, 3, 5, 7, 9 };
	vector<int> C = { 1, 3, 5, 7, 9, 11 };
	
	double result1 = s->findMedianSortedArrays(A, B);
	double result2 = s->findMedianSortedArrays(A, C);
	cout << "Solution 1: " << result1 << endl;
	cout << "Solution 1: " << result2 << endl;
	
	delete s;
	return 0;
}