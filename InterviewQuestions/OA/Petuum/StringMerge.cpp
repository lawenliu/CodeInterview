/*****************************************
* input是一个全letter的String，如果里面的两个相邻字母是同样的话，就可以remove这两个，最后return全部remove完的string
* 比如：s = “abbac”，最后会return “c”
*做法有各种各样的0.0，面试官貌似不是很在意用extra space，但是time complexity的要求比较高，反正最后不用brute force都应该没问题哒
*****************************************/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string stringMerge(string original) {
		stack<char> s;
		string result = "";
		for (int i = 0; i < original.size(); i++) {
			if (!s.empty() && original[i] == s.top()) {
				s.pop();
			} else {
				s.push(original[i]);
			}
		}
		
		while (!s.empty()) {
			char t = s.top();
			s.pop();
			result = t + result;
		}
		
		return result;
	}
	
	string stringMerge2(string original) {
		if (original.size() < 2) {
			return original;
		}
		
		string result = divideAndConquer(original);
		return result;
	}
	
	string divideAndConquer(string original) {
		if (original.size() < 2) {
			return original;
		}
		
		string left = divideAndConquer(original.substr(0, original.size() / 2));
		string right = divideAndConquer(original.substr(original.size() / 2));
		int leftIndex = left.size() - 1;
		int rightIndex = 0;
		bool equal = left[leftIndex] == right[rightIndex];
		while (leftIndex >= 0 && rightIndex < right.size() && equal) {
			leftIndex--;
			rightIndex++;
		}
		
		string result = leftIndex >= 0 ? left.substr(0, leftIndex + 1) : "";
		result += rightIndex < right.size() ? right.substr(rightIndex) : "";
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	string s1 = "abbac";
	string s2 = "abbbad";
	string s3 = "aabbcc";
	string s4 = "ababa";
	string s5 = "dcabbacd";
	cout << "Stack:" << endl;
	cout << s1 << ": " << s->stringMerge(s1) << endl;
	cout << s2 << ": " << s->stringMerge(s2) << endl;
	cout << s3 << ": " << s->stringMerge(s3) << endl;
	cout << s4 << ": " << s->stringMerge(s4) << endl;
	cout << s5 << ": " << s->stringMerge(s5) << endl;
	
	cout << endl;
	cout << "Merge:" << endl;
	cout << s1 << ": " << s->stringMerge2(s1) << endl;
	cout << s2 << ": " << s->stringMerge2(s2) << endl;
	cout << s3 << ": " << s->stringMerge2(s3) << endl;
	cout << s4 << ": " << s->stringMerge2(s4) << endl;
	cout << s5 << ": " << s->stringMerge2(s5) << endl;
	
	delete s;
	return 0;
}