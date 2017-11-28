/*******************************************
* 
*******************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(vector<vector<string>> codeList, vector<string> shoppingCart) {
		int startIndex = 0;
		for (auto codeLevel : codeList) {
			bool isFind = false;
			while (!isFind && startIndex + codeLevel.size() <= shoppingCart.size()) {
				if (codeLevel[0] != shoppingCart[startIndex]) {
					startIndex++;
					continue;
				}

				int i = 0;
				while (i < codeLevel.size() && codeLevel[i] == shoppingCart[startIndex+i]) {
					i++;
				}
				
				if (i == codeLevel.size()) {
					isFind = true;
					startIndex = startIndex + codeLevel.size();
				} else {
					startIndex++;
				}
			}
			
			if (!isFind) {
				return false;
			}
		}
		
		return true;
	}
};

int main(void) {
	Solution *s = new Solution();
	
	vector<vector<string>> codeList = {
		{"apple", "apple"},
		{"orange", "banana", "orange"}
	};
	
	vector<string> shoppingCart = {
		"Orange", "apple", "apple", "lychee", "orange", "banana", "orange"
	};
	
	cout << "result: " << s->isMatch(codeList, shoppingCart);
	
	delete s;
	return 0;
}