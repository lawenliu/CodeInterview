/***************************
* Given a set of non-overlapping intervals, insert a new interval into the
* intervals (merge if necessary).
* You may assume that the intervals were initially sorted according to their start times.
* Example 1: Given intervals [1,3], [6, 9], insert and merge [2, 5] in as [1, 5], [6, 9].
* Example 2: Given [1,2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge [4, 9] in as
* [1, 2], [3, 10], [12, 16].
* This is because the new interval [4, 9] overlaps with [3, 5], [6, 7], [8, 10].
***************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if (newInterval.end < it->start) {
				intervals.insert(it, newInterval);
				return intervals;
			} else if (newInterval.start > it->end) {
				it++;
			} else {
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}
		
		intervals.insert(intervals.end(), newInterval);
		return intervals;
	}
	
	void outputResult(vector<Interval> &intervals) {
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			cout << "[" << it->start << "," << it->end << "],";
			it++;
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<Interval> intervals1;
	Interval interval11(1, 3);
	Interval interval12(6, 9);
	intervals1.push_back(interval11);
	intervals1.push_back(interval12);
	Interval newInterval1(2, 5);
	vector<Interval> intervals2;
	Interval interval21(1, 2);
	Interval interval22(3, 5);
	Interval interval23(6, 7);
	Interval interval24(8, 10);
	Interval interval25(12, 16);
	intervals2.push_back(interval21);
	intervals2.push_back(interval22);
	intervals2.push_back(interval23);
	intervals2.push_back(interval24);
	intervals2.push_back(interval25);
	Interval newInterval2(4, 9);
	
	vector<Interval> result1 = s->insert(intervals1, newInterval1);
	vector<Interval> result2 = s->insert(intervals2, newInterval2);
	
	s->outputResult(result1);
	cout << endl;
	s->outputResult(result2);
	
	delete s;
	return 0;
}