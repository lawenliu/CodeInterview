/************************************
* Given two numbers represented as strings, return multiplication of the numbers as 
* a string.
* Note: The numbers can be arbitrarily large and non-negative.
************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<int> stringToVector(string num) {
		vector<int> result;
		for (int i = num.size() - 1; i >= 0; i--) {
			result.push_back(num[i] - '0');
		}
		
		return result;
	}
	
	string vectorToString(vector<int> num) {
		string result;
		for (int i = num.size() - 1; i >= 0; i--) {
			result.push_back(num[i] + '0');
		}
		
		return result;
	}
	
	vector<int> multiplyAux(vector<int> num1, vector<int> num2) {
		vector<int> result;
		for (int i = 0; i < num1.size(); i++) {
			for (int j = 0; j < num2.size(); j++) {
				if (i + j + 1 >= result.size()) {
					result.push_back(0);
					result.push_back(0);
				}
				result[i + j] += num1[i] * num2[j];
				result[i + j + 1] += result[i + j] / 10;
				result[i + j] %= 10;
			}
		}
		
		return result;
	}
public:
	/* Time: O(n*m), Space: O(n*m) */
	string multiply(string num1, string num2) {
		vector<int> num1Aux = stringToVector(num1);
		vector<int> num2Aux = stringToVector(num2);
		vector<int> result = multiplyAux(num1Aux, num2Aux);
		return vectorToString(result);
	}
};

int main(void) {
	Solution* s = new Solution();
	string num1 = "99";
	string num2 = "98";
	
	cout << "Solution 1: " << s->multiply(num1, num2) << endl;
	
	delete s;
	return 0;
}