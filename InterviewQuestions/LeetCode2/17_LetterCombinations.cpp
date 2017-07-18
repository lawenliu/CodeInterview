/******************************************************************
* Given a digit string, return all possible letter combination that
* the number could represent. A mapping of digit to letters (just like
* on the telephone button) is given below.
*           1()      2(abc) 3(def)
*           4(ghi)   5(jkl) 6(mno)
*           7(pqrs)  8(tuv) 9(wxyz)
*           *(+)     0( )   #()
* Input: Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* Note: Although the above is in lexicographical order, your answer
* could be in any order you want.
******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(const string digits) {
		vector<string> result;
		vector<int> path;
		letterCombinationsAux(digits, 0, "", result);
		
		return result;
	}
private:
	const vector<string> keyboard = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	
	void letterCombinationsAux(string digits, int cur, string path, vector<string> &result) {
		if (cur == digits.length()) {
			result.push_back(path);
			return;
		}
		
		int digit = digits[cur] - '0';
		for (int i = 0; i < keyboard[digit].length(); i++) {
			letterCombinationsAux(digits, cur + 1, path + keyboard[digit][i], result);
		}
	}
};

int main(void) {
	Solution *s = new Solution();
	string digits = "23";
	vector<string> result = s->letterCombinations(digits);
	for (int i = 0; i < result.size(); i++) {
		cout << "Combination " << i + 1 << ": " << result[i] << endl;
	}
	
	delete s;
	return 0;
}