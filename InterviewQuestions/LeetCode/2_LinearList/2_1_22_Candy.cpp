/************************************************
* There are N children standing in a line. Each child is assigned a rating value.
* You are giving candies to these children subjected to the following requirements:
* 1. Each child must have at least one candy.
* 2. Children with a higher rating get more candies than their neighbors.
* What is the minimum candies you must give?
************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> increment(n, 1);
		
		for (int i = 1; i < n; i++) {
			if (ratings[i] > ratings[i-1]) {
				increment[i] = max(increment[i-1] + 1, increment[i]);
			}
		}
		
		for (int i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i+1]) {
				increment[i] = max(increment[i+1] + 1, increment[i]);
			}
		}
		
		int result = 0;;
		for (int i = 0; i < n; i++) {
			result += increment[i];
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> ratings = { 3, 2, 3, 4, 4, 2, 5 };
	
	cout << "Solution: " << s->candy(ratings);
	
	delete s;
	return 0;
}