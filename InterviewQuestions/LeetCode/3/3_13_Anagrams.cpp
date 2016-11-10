/************************************
* Given an array of strings, return all groups of strings that are anagrams.
* Note: All inputs will be in lower-case.
************************************/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
	void merge(string &s, int first, int middle, int last) {
		string temp = "";
		int index1 = first;
		int index2 = middle + 1;
		while (index1 <= middle && index2 <= last) {
			if (s[index1] < s[index2]) {
				temp.append(1, s[index1]);
				index1++;
			} else {
				temp.append(1, s[index2]);
				index2++;
			}
		}
		
		while (index1 <= middle) {
			temp.append(1, s[index1]);
			index1++;
		}
		
		while (index2 <= last) {
			temp.append(1, s[index2]);
			index2++;
		}
		
		for (int i = 0; i < temp.length(); i++) {
			s[first+i] = temp[i];
		}
	}
	/* Time: O(nlgn), Space: O(1) */
	void mergeSort(string &s, int first, int last) {
		if (first < last) {
			int middle = (first + last) / 2;
			mergeSort(s, first, middle);
			mergeSort(s, middle + 1, last);
			merge(s, first, middle, last);
		}
	}
public:
	/* Time: O(nlgn), Space: O(n) */
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> group;
		for (int i = 0; i < strs.size(); i++) {
			string key = strs[i];
			mergeSort(key, 0, key.length() - 1);
			group[key].push_back(strs[i]);
		}
		
		vector<string> result;
		for (auto it = group.cbegin(); it != group.cend(); it++) {
			if (it->second.size() > 0) {
				for (int j = 0; j < it->second.size(); j++) {
					result.push_back(it->second[j]);
				}
			}
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	string s1 = "dormitory";
	string s3 = "are";
	string s4 = "ear";
	string s6 = "tt";
	string s5 = "rae";
	string s2 = "dirtyroom";
	vector<string> strs;
	strs.push_back(s1);
	strs.push_back(s2);
	strs.push_back(s3);
	strs.push_back(s4);
	strs.push_back(s5);
	strs.push_back(s6);
	
	vector<string> result = s->anagrams(strs);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	delete s;
	return 0;
}
