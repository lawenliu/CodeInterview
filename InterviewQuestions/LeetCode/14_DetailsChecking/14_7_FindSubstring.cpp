/*************************************
* You are given a string, S, and a list of words, L, that are all of the same length.
* Find all starting incies of substring(s) in S that is a concatenation of each words
* in L exactly once and without any intervening characters.
* For example, given:
* S: "barfoothefoobarman"
* L: ["foo", "bar"]
* You should return the indices: [0, 9]. (order does not matter).
*************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/* Time: O(n*m), Space: O(m) */
	vector<int> findSubstring(string s, vector<string> &dict) {
		vector<int> result;
		
		if (dict.size() == 0) {
			return result;
		}
		
		int wordLen = dict[0].length();
		int catWordLen = wordLen * dict.size();
		
		if ( s.length() < catWordLen) {
			return result;
		}
		
		unordered_map<string, int> wordExpectedCount;
		for (int i = 0; i < dict.size(); i++) {
			wordExpectedCount[dict[i]]++;
		}
		
		for (int i = 0; i < s.length() - catWordLen + 1; i++) {
			unordered_map<string, int> tempExpectedCount(wordExpectedCount);
			
			for (int j = i ; j < i + catWordLen; j += wordLen) {
				string tempWord = s.substr(j, wordLen);
				auto word = tempExpectedCount.find(tempWord);
				if (word != tempExpectedCount.end()) {
					word->second--;
				} else {
					break;
				}
				
				if (word->second < 0) {
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
	Solution* s = new Solution();
	string S = "barfoothefoobarman";
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	
	vector<int> result = s->findSubstring(S, L);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	delete s;
	return 0;
}