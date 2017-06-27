/********************************************************
* Given a string, find the length of the longest substring without
* repeating characters. For example, the longest substring without
* repeating letters for "abcabcbb" is "abc", which the length is 3.
* For "bbbbb" the longest substring is "b", with the length of 1.
********************************************************/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int lengthOfLongestSubstring(string s) {
		const int ASCII_NUMBER = 256; // We can store characters viewed information into 256 array
		int lastIndices[ASCII_NUMBER]; // becuase only 256 ASCII
		int lastStart = 0; // To reuse the 256 array
		int maxLength = 0;
		
		for (int i = 0; i < ASCII_NUMBER; i++) {
			lastIndices[i] = -1;
		}
		
		for (int i = 0; i < s.size(); i++) {
			if (lastIndices[s[i]] >= lastStart) {
				maxLength = max(maxLength, i - lastStart);
				lastStart = lastIndices[s[i]] + 1;
			}
			
			lastIndices[s[i]] = i;
		}
		
		maxLength = max(maxLength, (int)s.size() - lastStart);
		
		return maxLength;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "abcabcbb";
	string s2 = "bbbbb";
	
	cout << "Solution 1: " << s->lengthOfLongestSubstring(s1) << endl;
	cout << "Solution 1: " << s->lengthOfLongestSubstring(s2) << endl;
	
	delete s;
	return 0;
}