/*********************************************
* Input [itemA, itemB] means item A has association with item B
* Input [itemB, itemC] means item B has association with item C
* given an array find big group.
*********************************************/
#include <iostream>
#include <pair>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> findBigestGroup(vector<pair<string, string>> associations) {
		vector<string> res;
		map<string, int> m;
		int index = 1;
		for (var ass : associations) {
			if (m.find(ass.first) != associations.end()) {
				if (m.find(ass.second) != associations.end()) {
					int tt = m[ass.second];
					for (var as : m) {
						if (as.value == tt) {
							m[as.key] = tt;
						}
					}
				} else {
					m[ass.second] = m[ass.first];
				}
			} else if (m.find(ass.second) != associations.end()) {
				m[ass.first] = m[ass.second];
			} else {
				m[ass.first] = m[ass.second] = index;
				index++;
			}
		}
	}
}