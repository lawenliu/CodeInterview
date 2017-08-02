/****************************************
* Implement pow(x, n)
****************************************/
#include <iostream>
using namespace std;

class Solution {
public:
  /* Time: O(n), Space: O(1) */
	double myPow1(double x, int n) {
		if (n < 0) {
			return 1 / powAux1(x, -n);
		} else {
			return powAux1(x, n);
		}
	};
	
	double powAux1(double x, int n) {
		double result = 1.0;
		for (int i = 0; i < n; i++) {
			result *= x;
		}
		
		return result;
	}
	
	/* Time: O(logn), Space: O(1) */
	double myPow2(double x, int n) {
		if (n < 0) {
			return 1.0 / powAux2(x, -n);
		} else {
			return powAux2(x, n);
		}
	}
	
	double powAux2(double x, int n) {
		if (n == 0) {
			return 1.0;
		} else if (n == 1) {
			return x;
		} else {
			double half = powAux2(x, n / 2);
			double remaind = n % 2 == 0 ? 1.0 : x;
			return half * half * remaind;
		}
	}
};

int main(void) {
	Solution *s = new Solution();
	
	cout << s->myPow1(10, 3) << endl;
	cout << s->myPow1(10, -3) << endl;
	cout << s->myPow2(10, 3) << endl;
	cout << s->myPow2(10, -3) << endl;
	
	delete s;
	return 0;
}
