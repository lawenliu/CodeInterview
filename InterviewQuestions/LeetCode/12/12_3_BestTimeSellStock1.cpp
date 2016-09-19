/********************************************
* Say you have an array for which the i-th element is the price of a given stock on day i.
* If you were only permit to complete at most one transaction (ie, buy one and sell one share of the stock),
* design an algorithm to find the maximum profit.
********************************************/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(1) */
	int maxProfit1(vector<int> &prices) {
		int maxProfit = 0;
		
		for (int i = 0; i < prices.size() - 1; i++) {
			for (int j = i + 1; j < prices.size(); j++) {
				if (maxProfit < prices[j] - prices[i]) {
					maxProfit = prices[j] - prices[i];
				}
			}
		}
		
		return maxProfit;
	}
	
	/* Time: O(n), Space: O(1) */
	int maxProfit2(vector<int> &prices) {
		if (prices.size() < 2) {
			return 0;
		}
		
		int maxProfit = 0;
		int curMin = prices[0];
		
		for (int i = 1; i < prices.size(); i++) {
			if (maxProfit < prices[i] - curMin) {
				maxProfit = prices[i] - curMin;
			}
			
			if (curMin > prices[i]) {
				curMin = prices[i];
			}
		}
		
		return maxProfit;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> A1 = { 3, 2, 8, 1, 6, 3 };
	vector<int> A2 = { 3, 2, 8, 1, 9, 3 };
	
	cout << "Solution 1: " << s->maxProfit1(A1) << endl;
	cout << "Solution 1: " << s->maxProfit1(A2) << endl;
	
	cout << "Solution 2: " << s->maxProfit2(A1) << endl;
	cout << "Solution 2: " << s->maxProfit2(A2) << endl;
	
	delete s;
	
	return 0;
}