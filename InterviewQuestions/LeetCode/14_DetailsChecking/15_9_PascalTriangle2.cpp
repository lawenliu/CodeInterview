/*****************************
* Given an index k, return the kth row of the Pascal's triangle.
* For example, given k = 3,
* Return [1, 3, 3, 1].
* Note: Could you optimize your algorithm to use only O(k) extra space?
*****************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n^2), Space: O(n) */
	vector<int> getRow(int rowIndex) {
		vector<int> array;
		for (int i = 0; i < rowIndex; i++) {
			for (int j = i - 1; j > 0; j--) {
					array[j] = array[j] + array[j-1];
			}
			
			array.push_back(1);
		}
		
		return array;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	vector<int> array = s->getRow(5);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << ",";
	}
	
	delete s;
	return 0;
}
