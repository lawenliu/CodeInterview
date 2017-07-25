/********************************************************
* Given two words (start and end), and a dictionary, find all shortest
* transformation sequence(s) from start to end, such that:
* 1. Only one letter can be changed at a a time
* 2. Each intermediate word must exist in the dictionary
* For example, Given:
*  start = "hit"
*  end = "cog"
*  dict = ["hot", "dot", "dog", "lot", "log"]
* return
*  [
*	 ["hit", "hot", "dot", "dog", "cog"],
* 	 ["hit", "hot", "lot", "log", "cog"]
*  ]
* Note:
* 1. All words have the same length.
* 2. All words contain only lowercase alphabetic characters.
********************************************************/
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// Please test this one:
// start = "hit", end = "cog";
// dict = ["hot", "hig", "hog", "dot", "dog", "lot", "log"]
class Solution {
private:
	bool isValidState(const unordered_set<string> &dict, const string &s, const string &end) {
		return dict.find(s) != dict.end() || s == end;
	}
	
	bool isTargetState(const string &s, const string &end) {
		return s == end;
	}
	
	bool isVisited(const unordered_set<string> &visited, const string &s) {
		return  visited.find(s) != visited.end();
	}
	
	unordered_set<string> stateExtend(const unordered_set<string> &dict, const unordered_set<string> &visited,
		const string &s, const string &end) {
		unordered_set<string> result;
		for (int i = 0; i < s.size(); i++) {
			string newWord(s);
			for (char c = 'a'; c <= 'z'; c++) {
				if (c == newWord[i]) {
					continue;
				}
				
				swap(c, newWord[i]);
				
				if (isValidState(dict, newWord, end) && !isVisited(visited, newWord)) {
					result.insert(newWord);
				}
				
				swap(c, newWord[i]);
			}
		}
		
		return result;
	}
	
	void genPath(unordered_map<string, vector<string>> father, vector<string> &path, string start, string word, vector<vector<string>> &result) {
		path.push_back(word);
		if (word == start) {
			if (!result.empty()) {
				if (path.size() < result[0].size()) {
					result.clear();
					result.push_back(path);
				} else if (path.size() == result[0].size()) {
					result.push_back(path);
				} else {
					throw logic_error("not possible to get here.");
				}
			} else {
				result.push_back(path);
			}
			
			reverse(result.back().begin(), result.back().end());
		} else {
			for (auto w : father[word]) {
				genPath(father, path, start, w, result);
			}
		}
		
		path.pop_back();
	}
public:
	/* Time: O(n), Space: O(n) */
	vector<vector<string>> findLadders(const string &start, const string &end, const unordered_set<string> &dict) {
		unordered_set<string> current, next;
		unordered_set<string> visited;
		unordered_map<string, vector<string>> father;
		vector<vector<string>> result;
		
		int level = 0;
		current.insert(start);
		while (!current.empty()) {
			level++;
			if (!result.empty() && level > result[0].size()) {
				break;
			}
			
			for (auto state : current) {
				visited.insert(state);
			}
			
			for (auto state : current) {				
				if (isTargetState(state, end)) {
					vector<string> path;
					genPath(father, path, start, state, result);
					continue;
				}
				
				// don't add the new states in visted for this loop,
				// because some other word may have same extend on this same level
				const auto newStates = stateExtend(dict, visited, state, end);
				for (const auto newState : newStates) {
					next.insert(newState);
					father[newState].push_back(state);
				}
			}
			
			current.clear();
			swap(next, current);
		}
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
	// unordered_set<string> dict = { "hot", "hig", "hog", "dot", "dog", "lot", "log" };
	string start = "hit";
	string end = "cog";
	
	vector<vector<string>> result = s->findLadders(start, end, dict);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "Path " << i + 1 << ": ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		
		cout << endl;
	}
	
	delete s;
	return 0;
}