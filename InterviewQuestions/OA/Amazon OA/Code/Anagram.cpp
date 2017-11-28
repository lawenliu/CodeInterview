/*********************************************
* Anagram of string p in stirng s.
* return start position list
*********************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> findAnagram(string s, string p) {
		vector<int> m1(256, 0), m2(256, 0);
		vector<int> res;
		int n = p.size();
		
		for (int i = 0; i < n; i++) {
			m1[p[i]]++;
			m2[s[i]]++;
		}
		if (m1 == m2) {
			res.push_back(0);
		}
		
		for (int i = n; i < s.size(); i++) {
			m2[s[i]]++;
			m2[s[i-n]]--;
			
			if (m1 == m2) {
				res.push_back(i - n + 1);
			}
		}
		
		return res;
	}
};

int main(void) {
	Solution *s = new Solution();
	string ss = "cbaebabacd";
	string p = "abc";
	
	vector<int> res = s->findAnagram(ss, p);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", ";
	}
	
	delete s;
	return 0;
}

