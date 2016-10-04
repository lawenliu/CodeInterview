/*********************************
* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence
* where each word is a valid dictionary word.
* Return all such possible sentences.
* For example, given
* s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"]
* A solution is ["cats and dog", "cat sand dog"].
*********************************/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<vector<bool>> genBreakPositions(const string &s, unordered_set<string> &dict) {
		const int n = s.size();
		vector<vector<bool>> breakPositions(n + 1, vector<bool>(n, false));
		vector<bool> f(n + 1, false);
		
		f[0] = true;
		for (int i = 1; i < n + 1; i++) {
			for (int j = i -1; j >= 0; j--) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					breakPositions[i][j] = true;
				}
			}
		}
		
		return breakPositions;
	}
	
	void genPath(const string &s, const vector<vector<bool>> &breakPositions, int curPos, vector<string> &path, vector<string> &result) {
		if (curPos == 0) {
			string temp = "";
			for (int i = path.size() - 1; i >= 0; i--) {
				temp = temp + path[i] + " ";
			}
			
			temp.erase(temp.end() - 1);
			result.push_back(temp);
		}
		
		for (int i = 0; i < s.size(); i++) {
			if (breakPositions[curPos][i]) {
				path.push_back(s.substr(i, curPos - i));
				genPath(s, breakPositions, i, path, result);
				path.pop_back();
			}
		}
	}
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<vector<bool>> breakPositions = genBreakPositions(s, dict);
		vector<string> result;
		vector<string> path;
		genPath(s, breakPositions, s.size(), path, result);
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	string s1 = "catsanddog";
	
	vector<string> result = s->wordBreak(s1, dict);
	cout << "Solution 1: " << endl;
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "Word " << i + 1 << ": " << result[i] << endl;
	}
	
	delete s;
	return 0;
}
