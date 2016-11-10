/**********************************************************
* Given an absolute path for a file (Unix-style), simply it.
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* Corner Cases:
* Did you consider the case where path = "/../"? In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together,
* such as "/home//foo/". In this case, you should ignore redundant slashes and return "/home/foo".
**********************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(n) */
	string simplifyPath(const string &path) {
		string result;
		vector<string> dirs;
		
		string temp = "";
		for (int i = 0; i < path.length(); i++) {
			if (path[i] == '/') {
				if (!temp.empty() && temp != ".") {
					if (temp == "..") {
						if (!dirs.empty()) {
							dirs.pop_back();
						}
					} else {
						dirs.push_back(temp);
					}
				}
				
				temp = "";
			} else {
				temp.append(1, path[i]);
			}
		}
		
		if (dirs.empty()) {
			result = "/";
		} else {
			for (int i = 0; i < dirs.size(); i++) {
				result.append(1, '/');
				result.append(dirs[i]);
			}
		}
	
		return result;
	}
};

int main(void) {
	Solution* s = new Solution();
	string path1 = "/home/";
	string path2 = "/a/./b/";
	string path3 = "/a/./b/../../c/";
	string path4 = "/../";
	string path5 = "/home//foo/";
	
	cout << "Solution 1: " << s->simplifyPath(path1) << endl;
	cout << "Solution 1: " << s->simplifyPath(path2) << endl;
	cout << "Solution 1: " << s->simplifyPath(path3) << endl;
	cout << "Solution 1: " << s->simplifyPath(path4) << endl;
	cout << "Solution 1: " << s->simplifyPath(path5) << endl;
	
	delete s;
	return 0;
}