/*******************************************
* Given two list<String, String>, one is the employee and favorate food type,
* another is food type and food. Such as:
* list1:
*  Zhang san, Chinese food
*  Li si, American food
*  Wang wu, Japanese food
*  Zhao liu, *
* list2:
*  Chinese food, Yu xiang rou si
*  Chinese food, Shui zhu yu
*  American food, Hamburg
* Output:
*  Zhang san, Yu xiang rou si
*  Zhang san, Shui zhu yu
*  Li si, Hamburg
*  Zhao liu, Yu xiang rou si
*  Zhao liu, Shui zhu yu
*  Zhao liu, Hamburg
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<pair<string, string>> getMenu(vector<pair<string, string>> list1,
		vector<pair<string, string>> list2) {
		vector<pair<string, string>> res;
		unordered_map<string, unordered_set<string>> m;
		for (auto food : list2) {
			m[food.first].insert(food.second);
		}
		
		for (auto cf : list1) {
			if (cf.second == "*") {
				for (auto a : m) {
					for (string f : a.second) {
						res.push_back({cf.first, f});
					}
				}
			} else {
				for (string f : m[cf.second]) {
					res.push_back({cf.first, f});
				}
			}
		}
		
		return res;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<pair<string, string>> list1 = {
		{"Zhang san", "Chinese food"},
		{"Li si", "American food"},
		{"Wang wu", "Japanese food"},
		{"Zhao liu", "*"}
	};
	
	vector<pair<string, string>> list2 = {
		{"Chinese food", "Yu xiang rou si"},
		{"Chinese food", "Shui zhu yu"},
		{"American food", "Hamburg"}
	};
	
	vector<pair<string, string>> res = s->getMenu(list1, list2);
	for (auto r : res) {
		cout << "{" << r.first << "," << r.second << "}, ";
	}
	
	delete s;
	return 0;
}