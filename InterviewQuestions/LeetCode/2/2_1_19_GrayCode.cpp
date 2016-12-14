/**************************************************
* The gray code is a binary numerical system where two successive vlaues
* differ in only one bit.
* Given a not negative integer n representing the total number of bits
* int the code, print the sequence of gray code. A gray code sequence
* must begin with 0.
* For example, given n = 2, return [0, 1, 3, 2]. Its gray code sequence is:
*  00 - 0
*  01 - 1
*  11 - 3
*  10 - 2
* Note:
* 1. For a given n, a gray code sequence is not uniquely defined.
* 2. For exmple, [0, 2, 3, 1] is also a valid gray code sequence according
*    to the above definition.
* 3. For now, the judge is able to judge based on one instance of gray code
*    sequence. Sorry about that.
**************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	/* Binary to Gray: g0 = b0, gi = bi ^ bi-1 */
	/* Gray to Binary: b0 = g0, bi = gi ^ bi-1 */
	unsigned int binaryToGray(unsigned int k, int n) {
		unsigned int binary = k;
		unsigned int lastHighestBit = 1 << (k - 1);
		unsigned int highestBit = lastHighestBit >> 1;
		unsigned int gray = binary & lastHighestBit;
		
		for (int i = 1; i < n; i++) {
			gray |= ((binary & lastHighestBit) >> 1) ^ (binary & highestBit)	;
			
			lastHighestBit = highestBit;
			highestBit = lastHighestBit >> 1;
		}
		
		return gray;
	}
public:
	/* Time: O(2^n), Space: O(1) */
	vector<int> grayCode1(int n) {
		vector<int> result;
		const int size = 1 << n;
		for (int i = 0; i < size; i++) {
			result.push_back(binaryToGray(i, n));
		}
		
		return result;
	}
	
	/* Time: O(2^n), Space: O(1) */
	vector<int> grayCode2(int n) {
		vector<int> result;
		result.push_back(0);
		for (int i = 0; i < n; i++) {
			const int highestBit = 1 << i;
			for (int j = result.size() - 1; j >= 0; j--) {
				result.push_back(highestBit | result[j]);
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	cout << "Result 1:" << endl;
	vector<int> result = s->grayCode1(2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	cout << "Result 2:" << endl;
	result = s->grayCode2(2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	delete s;
	return 0;
}