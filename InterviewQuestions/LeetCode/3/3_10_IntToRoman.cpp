/********************************************
* Given an integer, convert it to a roman numeral.
* Input is guranteed to be within the range from 1 to 3999.
********************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	string intToRoman(int num) {
		int radixes[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string roman;
		int index = 0;
		while (num > 0) {
			int count = num / radixes[index];
			num = num % radixes[index];
			while (count > 0) {
				roman = roman + symbols[index];
				count--;
			}
			
			index++;
		}
		
		return roman;
	}
};

int main(void) {
	Solution* s = new Solution();
	int num1 = 3999;
	int num2 = 1;
	int num3 = 100;
	
	cout << "Solution 1: " << s->intToRoman(num1) << endl;
	cout << "Solution 1: " << s->intToRoman(num2) << endl;
	cout << "Solution 1: " << s->intToRoman(num3) << endl;
	
	delete s;
	return 0;
}