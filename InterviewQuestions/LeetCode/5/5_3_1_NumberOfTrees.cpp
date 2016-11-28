/***************************************************************
* Given n, how many structurally unique BST's (binary search trees) that store values 1..n?
* For example, Given n = 3, there are a total of 5 unique BST's.
*        1          3         3        2       1
*         \        /         /        / \       \
*          3      2         1        1   3       2
*         /      /           \                    \
*        2      1             2                    3
***************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(n) */
	/* f[i] as the number of trees with i nodes */
	/* f[0] = 1, f[1] = 1, f[i] = ++f(j-1) * f(i - j) (0 <= j <= i) */
	int numTrees(int n) {
		vector<int> f(n + 1, 0);
		f[0] = 1;
		f[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				f[i] += f[j-1] * f[i-j];
			}
		}
		
		return f[n];
	}
};

int main(void) {
	Solution* s = new Solution();
	int n = 3;
	
	cout << "Solution 1: " << s->numTrees(n) << endl;
	
	delete s;
	return 0;
}