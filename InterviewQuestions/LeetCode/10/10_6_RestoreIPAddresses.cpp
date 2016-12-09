/*******************************************************
* Given a string containing only digits, restore it by returning all possible
* valid IP address combinations.
* For example: Given "25525511135",
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*******************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void restoreIpAddressesAux(string s, vector<string> &ip, vector<string> &result, int start) {
		if (ip.size() == 4 && start == s.size()) {
			string ipStr = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
			result.push_back(ipStr);
			return;
		}
		
		if (s.size() - start > (4 - ip.size()) * 3) {
			return;
		}
		
		if (s.size() - start < (4 - ip.size())) {
			return;
		}
		
		int num = 0;
		for (int i = start; i < start + 3; i++) {
			num = num * 10 + (s[i] - '0');
			
			if (num < 0 || num > 255) {
				continue; // for '.'
			}
			
			ip.push_back(s.substr(start, i - start + 1));
			restoreIpAddressesAux(s, ip, result, i + 1);
			ip.pop_back();
			
			if (num == 0) break; // allow all to be 0, but not first one.
		}
	}
public:
	/* Time: O(n^4), Space: O(n) */
	vector<string> restoreIpAddresses(const string &s) {
		vector<string> result;
		vector<string> ip;
		restoreIpAddressesAux(s, ip, result, 0);
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	string ss = "25525511135";
	
	vector<string> result = s->restoreIpAddresses(ss);
	cout << "Solution :" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	delete s;
	return 0;
}