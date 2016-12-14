/**************************
* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated
* sequence of one or more dictionary words.
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
* Return true becuase "leetcode" can be seperated as "leet code".
**************************/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
	bool wordBreak1Aux(string s, unordered_set<string> &dict, int start, int end) {
		if (end == s.size() - 1) {
			return dict.find(s.substr(start, end - start + 1)) != dict.end();
		}
		
		if (wordBreak1Aux(s, dict, start, end + 1)) {
			return true;
		}
		
		if (dict.find(s.substr(start, end - start + 1)) != dict.end()) {
			return wordBreak1Aux(s, dict, end + 1, end + 1);
		}
		
		return false;
	}
public:
	/* Time: O(2^n), Space: O(1) */
	bool wordBreak1(string s, unordered_set<string> &dict) {
		return wordBreak1Aux(s, dict, 0, 0);
	}
	
	/* Time: O(n^2), Space: O(n) */
	/* f(i) = any(f(j) && s[j+1, i] in dict), 0 <= j < i
      f(i) is boolean value to say whether s[0, i] can be broken */
	bool wordBreak2(string s, unordered_set<string> &dict) {
		const int n = s.size();
		vector<bool> f(n + 1, false);
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		
		return f[n];
	}
};

int main(void) {
	Solution* s = new Solution();
	string s11 = "leetcode";
	string s12 = "leetacode";
	unordered_set<string> dict1;
	dict1.insert("leet");
	dict1.insert("code");
	string s21 = "aaaa";
	string s22 = "aaab";
	unordered_set<string> dict2;
	dict2.insert("a");
	
	cout << "Solution 1: " << s->wordBreak1(s11, dict1) <<endl;
	cout << "Solution 1: " << s->wordBreak1(s12, dict1) <<endl;
	cout << "Solution 1: " << s->wordBreak1(s21, dict2) <<endl;
	cout << "Solution 1: " << s->wordBreak1(s22, dict2) <<endl;
	cout << "Solution 2: " << s->wordBreak2(s11, dict1) <<endl;
	cout << "Solution 2: " << s->wordBreak2(s12, dict1) <<endl;
	cout << "Solution 2: " << s->wordBreak2(s21, dict2) <<endl;
	cout << "Solution 2: " << s->wordBreak2(s22, dict2) <<endl;
	
	delete s;
	return 0;
}
