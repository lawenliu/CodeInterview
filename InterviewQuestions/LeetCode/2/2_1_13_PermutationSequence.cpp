/*********************************************************
* The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
* By listing and labeling all of the permutations in order, we get the
* following sequence (ie, for n = 3).
*  "123"
*  "132"
*  "213"
*  "231"
*  "312"
*  "321"
* Given n and k, return the kth permutation sequence.
* Note: Given n will be between 1 and 9 inclusive.
*********************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void nextPermutation(vector<int> &nums) {
		if (nums.size() == 0) {
			return;
		}
		const int n = nums.size();
		int pivot = n - 2;
		for (; pivot >= 0; pivot--) {
			if (nums[pivot] < nums[pivot+1]) {
				break;
			}
		}
		
		if (pivot < 0) {
			reverse(nums.begin(), nums.end());
		}
		
		int change = n - 1;
		for(; change >= 0; change--) {
			if (nums[pivot] < nums[change]) {
				break;
			}
		}
		
		swap(nums[pivot], nums[change]);
		for (int i = pivot + 1, j = n - 1; i < (n + pivot + 1) / 2; i++, j--) {
			swap(nums[i], nums[j]);
		}
	}
	
	int factorial(int n) {
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
		
		return result;
	}
public:
	/* Time: O(n*n!), Space: O(n) */
	string getPermutation1(int n, int k) {
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			nums.push_back(i + 1);
		}
		
		for (int i = 0; i < k - 1; i++) {
			nextPermutation(nums);
		}
		
		string result;
		for (int i = 0; i < n; i++) {
			result += '0' + nums[i];
		}
		
		return result;
	}
	
	/* Time: O(n), Space: O(1) */
	string getPermutation2(int n, int k) {
		int base = factorial(n - 1);
		vector<int> nums;
		k--;
		for (int i = n - 1; i > 0; k %= base, base /= i, i--) {
			int a = k / base;
			nums.push_back(a);
		}
		
		string result;
		for (int i = 0; i < n; i++) {
			result += '0' + nums[i];
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	cout << "Solution 1: " << s->getPermutation1(3, 3) << endl;
	cout << "Solution 2: " << s->getPermutation1(3, 3) << endl;
	
	delete s;
	return 0;
}