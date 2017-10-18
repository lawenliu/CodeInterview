/****************************************************
* Check whether the binary of number is anagram.
* Such as 11011 (27) is anagram, 11 (3) is anagram
****************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(int num) {
		int len = 0;
		int tmp = num;
		while (tmp / 2 > 0) {
			len++;
			tmp /= 2;
		}
		
		tmp = num;
		while (tmp > 0) {
			if ((tmp >> len) != (tmp & 1)) {
				return false;
			}
			
			tmp &= (1 << len) - 1;
			tmp /= 2;
			len -= 2;
		}
		
		return true;
	}
};

int main() {
	Solution* s = new Solution();
	int num = 5;
	
	cout << "The number " << num << " is " << s->isAnagram(num) << endl;
	
	delete s;
	return 0;
}


