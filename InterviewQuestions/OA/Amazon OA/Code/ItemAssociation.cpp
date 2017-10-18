/*********************************************
* Input [itemA, itemB] means item A has association with item B
* Input [itemB, itemC] means item B has association with item C
* given an array find big group.
*********************************************/
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> findBigestGroup(vector<pair<string, string>> associations) {
		vector<string> res;
		map<string, int> m;
		int index = 1;
		for (auto ass : associations) {
			if (m.find(ass.first) != m.end()) {
				if (m.find(ass.second) != m.end()) {
					int t1 = m[ass.first];
					int t2 = m[ass.second];
					for (auto as : m) {
						if (as.second == t2) {
							m[as.first] = t1;
						}
					}
				} else {
					m[ass.second] = m[ass.first];
				}
			} else if (m.find(ass.second) != m.end()) {
				m[ass.first] = m[ass.second];
			} else {
				m[ass.first] = m[ass.second] = index;
				index++;
			}
		}
		
		for (auto as : m) {
			if (as.second == 0) {
				continue;
			}
			
			int val = as.second;
			vector<string> tmp;			
			for (auto a : m) {
				if (a.second == val) {
					tmp.push_back(a.first);
					a.second = 0;
				}
			}
			
			if (tmp.size() > res.size()){
				res = tmp;
			}
		}
		
		return res;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<pair<string, string>> associations;
	associations.push_back({"D", "E"});
	associations.push_back({"E", "F"});
	associations.push_back({"A", "B"});
	associations.push_back({"A", "C"});
	associations.push_back({"G", "H"});
	//associations.push_back({"G", "D"});
	
	vector<string> res = s->findBigestGroup(associations);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", ";
	}
	
	delete s;
	return 0;
}