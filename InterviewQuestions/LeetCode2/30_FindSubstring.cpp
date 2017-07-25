/**************************************************************
* You are given a string s, and list of words, that are all of
* same length. Find all starting indices of substring(s) in s
* that is a concatenation of each word in words exactly once and
* without any intervening characters.
* For example, given:
* s: "barfoothefoobarman"
* words: ["foo", "bar"]
* You should return the indices: [0, 9].
* (order does not matter).
**************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/**/
	vector<int> findSubstring(string s, vector<string> &dict) {
		vector<int> result;
		
		if(dict.size() == 0) {
			return result;
		}
		
		int wordLen = dict[0].length();
		int catWordLen = wordLen * dict.size();
		
		if (s.length() < catWordLen) {
			return result;
		}
		
		unordered_map<string, int> wordExpectedCount;
		for (int i = 0; i < dict.size(); i++) {
			wordExpectedCount[dict[i]] = 1;
		}
		
		for (int i = 0; i < s.length() - catWordLen + 1; i++) {
			unordered_map<string, int> tempExpectedCount(wordExpectedCount);
			
			for (int j = i; j < i + catWordLen; j += wordLen) {
				string tempWord = s.substr(j, wordLen);
				auto word = tempExpectedCount.find(tempWord);
				if (word != tempExpectedCount.end()) {
					word->second--;
				} else {
					break;
				}
				
				if (word->second < 0) { // We may not need this check.
					break;
				} else if (word->second == 0) {
					tempExpectedCount.erase(word);
				}
			}
			
			if (tempExpectedCount.size() == 0) {
				result.push_back(i);
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	string s1 = "barfoothefoobarman";
	vector<string> words1, words2;
	words1.push_back("foo");
	words1.push_back("bar");
	
	words2.push_back("bar");
	words2.push_back("man");
	
	vector<int> result = s->findSubstring(s1, words1);
	cout << "Solution1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	
	cout << endl;
	
	result = s->findSubstring(s1, words2);
	cout << "Solution1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	
	delete s;
	return 0;
}
