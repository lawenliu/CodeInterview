/************************
* Description:
*  Implement int sqrt(int x).
*  Compute and return the square root of x. 
************************/
#include <iostream>
using namespace std;

class Solution {
public:
	/* Assume x is valid, check when interviewing */
	int mySqrt(int x) {
		int left = 0, right = x;
		int mid = 0;
		
		while (left <= right) {
			mid = (left + right) / 2;
			
			if(x / mid < mid) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		
		return mid;
	}
};

int main(void) {
	Solution* s = new Solution();
	cout << s->mySqrt(100) << endl;
	cout << s->mySqrt(90) << endl;
	
	delete s;
	
	return 0;
}
