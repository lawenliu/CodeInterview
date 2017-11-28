
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
				int size = haystack.size() - needle.size() + 1;
        for (int i = 0; i < size; i++) {
            int j = i;
            int k = 0;
            while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
							  cout << j << " " << k << endl;
                j++;
                k++;
            }
            
            if (k == needle.size()) {
                return i;
            }
						
        }
        
        return -1;
    }
};

int main(void) {
	Solution *s = new Solution();
	string haystack = "abb";
	string needle = "abaaa";
	
	cout << "Solution: " << s->strStr(haystack, needle);
	
	delete s;
	return 0;
}
