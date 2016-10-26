/****************************************
* Given an array of words and length L, format the text such that each line has exactly L
* characters and is fully (left and right) justified.
* You should pack your words in a greedy approach; that is, pack as many words as you can
* in each line. Pad extra spaces ' ' when neccessary so that each line has exactly L characters.
* Extra spaces between words should be distributed as evenly as possible. If the number of
* spaces on a line do not divide evently between words, the empty slots on the left will be assigned
* more spaces than the slots on the right.
* For the last line of text, it should be left justified and no extra spaces is inserted
* between words.
* For example,
* words: ["This", "is", "an", "example", "of", "text", "justification."]
* L : 16.
* Return the formatted lines as:
*   [
      "This   is    an",
			"example of text",
			"justification. "
*   ]
* Note: Each word is guaranteed not to exceed L in length.
* Corner cases:
* 1. A line other that the last line might contain only one word. What should you do in this case?
* 2. In this case, that line should be left
****************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	/*
		s: the one string line
		i: current space index
		n: total positons to fill spaces
		L: total number of spaces
		is_last: is last or not
	*/
	void addSpaces(string &s, int i, int n, int L, bool is_last) {
		if (n < 1 || i > n - 1) {
			return;
		}
		
		int spaces =  is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
		s.append(spaces, ' ');
	}
	
	/*
		words: word list
		start: start index of word list
		end: end index of word list
		len: length of all words
		L: length of the line
		is_last: is last or not
	*/
	string connect(vector<string> &words, int start, int end,
		int len, int L, bool is_last) {
		string s;
		int n = end - start + 1;
		for (int i = 0; i < n; i++) {
			s += words[start + i];
			addSpaces(s, i, n - 1, L - len, is_last);
		}
		
		if (s.size() < L) {
			s.append(L - s.size(), ' ');
		}
		
		return s;
	}
public:
	/* Time: O(n), Space: O(1) */
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		int start = 0;
		int len = 0;
		for (int i = 0; i < words.size(); i++) {
			if (len + words[i].size() + (i - start) > L) { // added words length + next words length + space number
				string line = connect(words, start, i - 1, len, L, false);
				result.push_back(line);
				start = i;
				len = 0;
			}
			
			len += words[i].size();
		}
		
		// The last line not exceed L
		string line = connect(words, start, words.size() - 1, len, L, true);
		result.push_back(line);
		
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	
	vector<string> result = s->fullJustify(words, 16);
	cout << "Solution 1: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << "" << result[i] << "," << endl;
	}
	
	delete s;
	return 0;
}