/**********************************************************
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999.
**********************************************************/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: (1) */
	int romanToInt(const string &s) {
		unordered_map<char, int> map { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000} };
		int result = 0;
		for (int i = 0; i < s.length(); i++) {
			if (i > 0 && (map[s[i]] > map[s[i-1]])) {
				result += (map[s[i]] - 2 * map[s[i-1]]);
			} else {
				result += map[s[i]];
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	string s1 = "IVCLXMDDII";
	string s2 = "DDXI";
	
	cout << "Solution 1: " << s->romanToInt(s1) << endl;
	cout << "Solution 1: " << s->romanToInt(s2) << endl;
	
	delete s;
	return 0;
}