/********************************************
* There are two sorted arrays A and B of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time
* complexity should be O(log(m + n))
********************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(log(m+n)), Space: O(m+n) */
	double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
		const int m = A.size();
		const int n = B.size();
		int total = m + n;
		if (total % 2 == 0) {
			
		}
	}
}