/***********************************************
* Implement strStr().
* Returns a pointer to the first occurrence of needle in haystack, or null if needle
* is not part of haystack.
***********************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int> computePrefix(const string &pattern) {
		int i = 0;
		int j = -1;
		vector<int> next;
		next.push_back(j);
		for (int i = 1; i < pattern.length(); i++) {
			while (j > -1 && pattern[j+1] != pattern[i]) {
				j = next[j];
			}
			
			if (pattern[j+1] == pattern[i]) {
				j++;
			}
			
			next.push_back(j);
		}
		
		return next;
	}
	
	int kmp(const string &text, const string &pattern) {
		int i;
		int j = -1;
		if (pattern.length() == 0) {
			return 0;
		}
		
		if (text.length() == 0) {
			return 0;
		}
		
		vector<int> next = computePrefix(pattern);
		for (i = 0; i < text.length(); i++) {
			while (j > -1 && pattern[j+1] != text[i]) {
				j = next[j];
			}
			
			if (pattern[j+1] == text[i]) {
				j++;
			}
			
			if (j == pattern.length() - 1) {
				return i - j;
			} 
		}
		
		return -1;
	}
public:
	/* Time: O(n*m), Space: O(1) */
	int strStr1(const string &haystack, const string &needle) {
		if (needle.empty()) {
			return 0;
		}
		
		for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
			int k = i;
			int j = 0;
			for (j = 0; j < needle.length(); j++) {
				if (haystack[k] != needle[j]) {
					break;
				}
				
				k++;
			}
			
			if (j == needle.length()) {
				return i;
			}
		}
		
		return -1;
	}
	
	/* Time: O(n+m), Space: O(m) */
	int strStr2(const string &haystack, const string needle) {
		return kmp(haystack, needle);
	}
};

int main(void) {
	Solution* s = new Solution();
	string haystack = "abaababcbababd";
	string needle1 = "ababc";
	string needle2 = "abcd";
	string needle3 = "";
	
	cout << "Solution 1: " << s->strStr1(haystack, needle1) << endl;
	cout << "Solution 1: " << s->strStr1(haystack, needle2) << endl;
	cout << "Solution 1: " << s->strStr1(haystack, needle3) << endl;
	cout << "Solution 2: " << s->strStr2(haystack, needle1) << endl;
	cout << "Solution 2: " << s->strStr2(haystack, needle2) << endl;
	cout << "Solution 2: " << s->strStr2(haystack, needle3) << endl;
	
	delete s;
	return 0;
}
