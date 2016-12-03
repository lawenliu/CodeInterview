/************************************************
* Given two words (start and end), and a dictionary, find the length of 
* shortest transformation sequence from start to end, such that:
* 1. Only one letter can be changed at a time
* 2. Each intermediate word must exist in the dictionary
* For example, Given:
*  start = "hit"
*  end = "cog"
*  dict = "hot", "dot", "dog", "lot", "log"]
* As one shortest transformation is "hit"->"hot"->"dot"->"dog"->"cog",
* return its length 5.
* Note:
* 1. Return 0 if there is no such transformation sequence.
* 2. All words have the same length.
* 3. All words contain only lowercase alphabetic characters.
************************************************/
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

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
public:
	/* Time: O(n), Space: O(n) */
	int ladderLength(const string &start, const string &end, const unordered_set<string> &dict) {
		queue<string> current, next;
		unordered_set<string> visited;
		
		int level = 0;
		current.push(start);
		visited.insert(start);
		while (!current.empty()) {
			level++;
			while (!current.empty()) {
				const auto state = current.front();
				current.pop();
				
				if (isTargetState(state, end)) {
					return level;
				}
				
				const auto newStates = stateExtend(dict, visited, state, end);
				for (const auto newState : newStates) {
					next.push(newState);
					visited.insert(newState);
				}
			}
			
			swap(next, current);
		}
		
		return 0;
	}
};

int main(void) {
	Solution* s = new Solution();
	
	unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
	string start = "hit";
	string end = "cog";
	
	cout << "Solution 1: " << s->ladderLength(start, end, dict) << endl;
	
	delete s;
	return 0;
}