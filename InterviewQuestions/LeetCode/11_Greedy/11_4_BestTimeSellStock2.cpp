/****************************
* Say you have an array for whick the i-th element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete as many transaction as you like (ie,
* buy one and sell one share of the stock multiple times). However, you may not engate in multiple
* transaction at the same time (ie, you must sell the stock before you buy again).
****************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int maxProfit(vector<int> &prices) {
		int maxProfit = 0;
		
		for (int i = 0; i < prices.size() - 1; i++) {
			int diff = prices[i + 1] > prices[i] ? prices[i + 1] - prices[i] : 0;
			maxProfit += diff;
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