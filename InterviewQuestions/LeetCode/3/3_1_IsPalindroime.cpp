/*******************************************
* Giving a string, determine if it is a palindrome, considering only alphanumeric
* characters and ignoring cases.
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
* Note: Have you consider that the string might be empty? This is a good question to
* ask during an interview.
* For the purpose of this problem, we define empty string as valid palindrome. 
*******************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	bool isAlphaNumeric(char c) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
			return true;
		}
		
		return false;
	}
	
	bool isEqualIgnoreCase(char c1, char c2) {
		if (c1 >= 'A' && c1 <= 'Z') {
			c1 = c1 + 32;
		}
		
		if (c2 >= 'A' && c2 <= 'Z') {
			c2 = c2 + 32;
		}
		
		return c1 == c2;
	}
public:
  /* Time: O(n), Space: O(1) */
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.length();
		
		while (left < right) {
			if (!isAlphaNumeric(s[left])) {
				left++;
			} else if (!isAlphaNumeric(s[right])) {
				right--;
			} else if (!isEqualIgnoreCase(s[left], s[right])) {
				return false;
			} else {
				left++;
				right--;
			}
		}
		
		return true;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	
	cout << "Solution 1: " << s->isPalindrome(s1) << endl;
	cout << "Solution 1: " << s->isPalindrome(s2) << endl;
	
	delete s;
	return 0;
}
