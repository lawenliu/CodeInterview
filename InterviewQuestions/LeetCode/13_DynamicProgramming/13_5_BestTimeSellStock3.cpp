/***********************************
* Say you have an array for which the i-th element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
* Note: You may not engate in multiple transaction at the same time (ie, you must sell
* the stock before you buy again).
***********************************/
#include <iostream>
#include <vector>
#include < algorithm>
using namespace std;

class Solution {
public:
	/* maxProfit = max(f(x) + g(x)), 0 <= x < n, */
	/* f(x) is max profit from 0 to x, g(x) is max profit from x to n */
	/* Time: O(n), Space: O(n) */
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2) {
			return 0;
		}
		
		int maxProfit = 0;
		int n = prices.size();
		vector<int> f(n, 0);
		vector<int> g(n, 0);
		
		int curMin = prices[0];
		for (int i = 0; i < n; i++) {
			if (curMin > prices[i]) {
				curMin = prices[i];
			}
			
			f[i] = max(f[i - 1], prices[i] - curMin);
		}
		
		int curMax = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (curMax < prices[i]) {
				curMax = prices[i];
			}
			
			g[i] = max(g[i + 1], curMax - prices[i]);
		}
		
		for (int i = 0; i < n; i++) {
			maxProfit = max(maxProfit, f[i] + g[i]);
		}
		
		return maxProfit;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A1 = { 3, 2, 8, 1, 6, 3 };
	vector<int> A2 = { 3, 2, 8, 1, 9, 3 };
	
	cout << "Solution 1: " << s->maxProfit(A1) << endl;
	cout << "Solution 1: " << s->maxProfit(A2) << endl;
	
	delete s;
	
	return 0;
}
