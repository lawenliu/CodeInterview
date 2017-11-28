/*********************************************
* Book association based on book pair <bookA, bookB>
* Find bigest book collection
*********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
private:
	void unionFind(map<string, int> &m, pair<string, string> as) {
		int g1 = m[as.first];
		int g2 = m[as.second];
		for (auto a : m) {
			if (a.second == g2) {
				m[a.first] = g1;
			}
		}
	}
public:
	vector<string> findBigestBookCollection(vector<pair<string, string>> associations) {
		vector<string> res;
		map<string, int> m;
		
		int n = 0;
		for (auto as : associations) {
			if (m.find(as.first) == m.end()) {
				n++;
				m[as.first] = n;
			}
			
			if (m.find(as.second) == m.end()) {
				n++;
				m[as.second] = n;
			}
		}
		
		for (auto as : associations) {
			unionFind(m, as);
		}
		
		int maxNum = 0;
		for (auto a : m) {
			if (a.second == -1) {
				continue;
			}
			
			vector<string> temp;
			for (auto aa : m) {
				if (aa.second == a.second) {
					temp.push_back(aa.first);
					aa.second = -1;
				}
			}
			
			if (temp.size() > res.size()) {
				res = temp;
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
	associations.push_back({"G", "D"});
	
	vector<string> res = s->findBigestBookCollection(associations);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", ";
	}
	
	delete s;
	return 0;
}