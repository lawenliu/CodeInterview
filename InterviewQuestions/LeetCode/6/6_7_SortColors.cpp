/*******************************************
* Given an array with n objects colored red, white or blue, sort them so that objects
* of the same color are adjacent, with the colors in the order red, white and blue.
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and
* blue respectively.
* Note: You are note suppose to use the library's sort function for this problem.
* Follow up:
* A rather straight forward solution is a two-pass algorithm using counting sort.
* First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
* array with total number of 0's, then 1's and followed by 2's.
* Could you come up with an one-pass algorithm using only constant space?
*******************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	/* Counting two-pass */
	void sortColors1(vector<int> &A) {
		int count[3] = { 0 };
		for (int i = 0; i < A.size(); i++) {
			count[A[i]]++;
		}
		
		int index = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < count[i]; j++) {
				A[index] = i;
				index++;
			}
		}
	}
	
	/* Time: O(n), Space: O(1) */
	/* Two pointers */
	void sortColors2(vector<int> &A) {
		int i = 0; // For red;
		int j = A.size() - 1; // For blue
		int k = 0; // For index
		while (k <= j) {
			if (A[k] == 0) {
				swap(A[i], A[k]);
				i++;
				k++;
			} else if (A[k] == 2) {
				swap(A[j], A[k]);
				j--;
			} else {
				k++;
			}
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A = { 2, 1, 1, 2, 2, 0, 0, 2, 1, 0 };
	vector<int> B = { 2, 1, 1, 2, 2, 0, 0, 2, 1, 0 };
	
	s->sortColors1(A);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	
	s->sortColors2(B);
	cout << endl << "Solution 1: " << endl;
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << " ";
	}
	
	delete s;
	return 0;
}