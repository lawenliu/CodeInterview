/*************************************************************
* There are n different online courses numbered from 1 to n.
* Each course has some duration (course length) t and closed
* on dth day. You will start at the 1st day.
* Given n online courses represented by pairs (t, d), your task
* is to find the maximal number of course that can be taken.
* Example:
*  Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
*  Output: 3
*  Explanation:
*  There're totally 4 courses, but you can tack 3 courses at most:
*  First, take the 1st course, it costs 100 days so you will finish
*  it on the 100th day, and ready to take the next course on the
*  101st day.
*  Second, take the 3rd course, it costs 1000 days so you will
*  finish it on the 1100th day, and ready to take the next course
*  on the 1101st day.
*  Third, take the 2nd course, it costs 200 days so you will finish
*  on the 1300th day.
*  The 4th course cannot be taken now, since you will finish it
*  on the 3300th day, which exceeds the closed date.
* Note:
*  1. The integer 1 <= d, n <= 10,000.
*  2. You can't take two courses simultaneously.
**************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:

public:
	/* Time: O(2^n), Space: O(1) */
	/* Brute-force*/
	int scheduleCourse(vector<vector<int>> &courses) {
		
	}

	/* Time: O(n), Space: O(n) */
	/* Greedy algorithm */
	int scheduleCourse(vector<vector<int>> &courses) {
		int curTime = 0;
		priority_queue<int> q;
		// Sort the courses list based on closed time
		sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
		
		for (auto course : courses) {
			curTime += course[0];
			q.push(course[0]);
			// If we can't take this course then we need delete the course using longest time
			if (curTime > course[1]) {
				curTime -= q.top();
				q.pop();
			}
		}
		
		return q.size();
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<vector<int>> courses = {
		{ 100, 200 },
		{ 200, 1300 },
		{ 1000, 1250 },
		{ 2000, 3200 }
	};
	
	cout << s->scheduleCourse(courses) << endl;
	
	return 0;
}