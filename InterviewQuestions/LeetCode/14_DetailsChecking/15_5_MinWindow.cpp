/*********************************
* Given a string S and a string T, find the minimum window in S which will contain all the characters
* in T in complexity O(n).
* For example, S = "ADOBECODEBANC", T = "ABC".
* Minimum window is "BANC".
* Note:
* If there is no such window in S that covers all characters in T, return the empty string "".
* If there are multiple such windows, you are guranteed that there will always be only one unique
* minimum window in S.
*********************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	string minWindow(string S, string T) {
		if (S.empty() || T.empty() || S.size() < T.size()) {
			return "";
		}
		
		const int ASCII_LENGTH = 256;
		int appearedCount[ASCII_LENGTH];
		int expectedCount[ASCII_LENGTH];
		fill(appearedCount, appearedCount + ASCII_LENGTH, 0);
		fill(expectedCount, expectedCount + ASCII_LENGTH, 0);
		
		for (int i = 0; i < T.size(); i++) {
			expectedCount[T[i]]++;
		}
		
		int minWndStart = 0;
		int minWndWidth = INT_MAX;
		int wndStart = 0;
		int expectedAppearedCount = 0;
		
		for (int wndEnd = 0; wndEnd < S.size(); wndEnd++) {
			if (expectedCount[S[wndEnd]] > 0) {
				appearedCount[S[wndEnd]]++;
				if (appearedCount[S[wndEnd]] <= expectedCount[S[wndEnd]]) {
					expectedAppearedCount++;
				}
			}
			
			if (expectedAppearedCount == T.size()) {
				while (appearedCount[S[wndStart]] > expectedCount[S[wndStart]] || expectedCount[S[wndStart]] == 0) {
					if (expectedCount[S[wndStart]] > 0) {
						appearedCount[S[wndStart]]--;
					}
					
					wndStart++;
				}
				
				if (minWndWidth > wndEnd - wndStart) {
					minWndWidth = wndEnd - wndStart + 1;
					minWndStart = wndStart;
				}
			}
		}
		
		if (minWndWidth == INT_MAX) {
			return "";
		} else {
			return S.substr(minWndStart, minWndWidth);
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	string S = "ADOBECODEBANC";
	string T = "ABC";
	
	cout << "Solution 1: " << s->minWindow(S, T) << endl;
	
	delete s;
	return 0;
}