/***********************************
* Given a collection of intervals, merge all overlapping intervals.
* For example, given [1, 3], [2, 6], [8, 10], [15, 18], return [1, 6], [8, 10], [15, 18]
***********************************/
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
private:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> :: iterator it = intervals.begin();
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
public:
  /* Time: O(n^2), Space: O(1) */
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> result;
		for (int i = 0; i < intervals.size(); i++) {
			result  = insert(result, intervals[i]);
		}
		
		return result;
	}
	
	void outputResult(vector<Interval> &intervals) {
		vector<Interval> result;
		for (int i = 0; i < intervals.size(); i++) {
			cout << "[" << intervals[i].start << "," << intervals[i].end << "],";
		}
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<Interval> intervals;
	Interval interval1(1, 3);
	Interval interval2(2, 6);
	Interval interval3(8, 10);
	Interval interval4(15, 18);
	intervals.push_back(interval1);
	intervals.push_back(interval2);
	intervals.push_back(interval3);
	intervals.push_back(interval4);
	
	vector<Interval> result = s->merge(intervals);
	s->outputResult(result);
	
	delete s;
	return 0;
}