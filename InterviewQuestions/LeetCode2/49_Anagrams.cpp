/*****************************************************************
* Given an array of strings, group anagrams together.
* For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
* Return:
*  [
*    ["ate", "eat", "tea"],
*    ["nat", "tan"],
*    ["bat"]
*  ]
* Note: All inputs will be in lower-case.
*****************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/* Time: O(n*(mlogm)), Space: O(n) */
	/* Based on sorting string */
	vector<vector<string>> groupAnagrams1(vector<string> &strs) {
		unordered_map<string, vector<string>> group;
		for (int i = 0; i < strs.size(); i++) {
			string key = strs[i];
			sort(key.begin(), key.end());
			group[key].push_back(strs[i]);
		}
		
		vector<vector<string>> result;
		for (auto it = group.cbegin(); it != group.cend(); it++) {
			if (it->second.size() > 0) {
				result.push_back(it->second);
			}
		}
		
		return result;
	}
	
	/* Time: O(n*(m)), Space: O(n) */
	/* Based on letter count rather than sorting */
	vector<vector<string>> groupAnagrams2(vector<string> &strs) {
		unordered_map<string, vector<string>> group;
		for (int i = 0; i < strs.size(); i++) {
			int *cnt = new int[26]();
			for (int j = 0; j < strs[i].length(); j++) {
				cnt[strs[i][j] - 'a']++;
			}
			
			string key("");
			for (int j = 0; j < 26; j++) {
				key += to_string(cnt[j]) + '/';
			}
			
			group[key].push_back(strs[i]);
		}
		
		vector<vector<string>> result;
		for (auto v : group) {
			result.push_back(v.second);
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	string s1 = "dormitory";
	string s3 = "are";
	string s4 = "ear";
	string s6 = "tt";
	string s5 = "rae";
	string s2 = "dirtyroom";
	vector<string> strs = { s1, s2, s3, s4, s5, s6 };
	
	vector<vector<string>> result = s->groupAnagrams1(strs);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
		  cout << result[i][j] << "; ";
		}
		
		cout << endl;
	}
	
	result = s->groupAnagrams2(strs);
	cout << "Solution 2: " << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
		  cout << result[i][j] << "; ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}
