/***************************************************
* The count-and-say sequence is the sequence of integers beginning as following:
* 1, 11, 21, 1211, 111221, ...
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2" and then "one 1" or 1211.
* Given an integer n, generate the nth sequence.
* Notice: The sequence of integers will be represented as a string.
***************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	string getNext(string s) {
		string result = "";
		char last = s[0];
		int count = 1;
		for (int i = 1; i < s.length(); i++) {
			if (last != s[i]) {
				result.append(1, '0' + count);
				result.append(1, last);
				last = s[i];
				count = 1;
			} else {
				count++;
			}
		}
		
		result.append(1, '0' + count);
		result.append(1, last);
		cout << result << endl;
		return result;
	}
public:
	/* Time: O(n^2), Space: O(n) */
	string countAndSay(int n) {
		string s("1");
		
		while (n > 0) {
			s = getNext(s);
			n--;
		}
		
		return s;
	}
};

int main(void) {
	Solution *s = new Solution();
	int n1 = 4;
	int n2 = 6;
	
	cout << "Solution 1: " << s->countAndSay(n1) << endl;
	cout << "Solution 1: " << s->countAndSay(n2) << endl;
	
	delete s;
	return 0;
}