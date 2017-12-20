/**********************************************
* Given an array of meeting time intervals consisting of start and end
* times [[s1, e1], [s2, e2], ...](si < ei), find the minimum number of
* conference rooms required.
* For example,
* Given [[0, 30], [5, 10], 15, 20]],
* return 2.
**********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval(int s, int e) : start(s), end(e) {};
};
	
class Solution {
private:
	
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		map<int, int> m;
		for (auto a : intervals) {
			m[a.start]++;
			m[a.end]--;
		}
		
		int result = 0, rooms = 0;
		for (auto p : m) {
			result = max(result, rooms += p.second);
		}
		
		return result;
	}

	int minMeetingRooms1(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
			return a.start < b.start;
		});
		
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto a : intervals) {
			if (!q.empty() && q.top() <= a.start) {
				q.pop();
			}
			
			
			q.push(a.end);
		}
		
		return q.size();
	}
};

int main(void) {
	Solution *s = new Solution();
	
	vector<Interval> intervals;
	intervals.push_back(Interval(0, 30));
	intervals.push_back(Interval(5, 10));
	intervals.push_back(Interval(15, 20));
	
	int result = s->minMeetingRooms(intervals);
	cout << "Result: " << result << endl;
	
	delete s;
	return 0;
}

