/*******************************************************
* Given n points on a 2D plane, find the maximum number of points
* that lie on the same straight line.
*******************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x;
	double y;
	
	Point(int px, int py): x(px), y(py) {}
	Point(): x(0), y(0) {}
};

class Solution {
public:
	/* Time: O(n^3), Space: O(1) */
	int maxPoints1(vector<Point> &points) {
		if (points.size() < 3) {
			return points.size();
		}
		
		int maxCount = 0;
		for (int i = 0; i < points.size() - 1; i++) {
			for (int j = i + 1; j < points.size(); j++) {
				int vSign = 0;
				int a, b, c;
				if (points[i].x == points[j].x) {
					vSign = 1;
				} else {
					a = points[j].x - points[i].x;
					b = points[j].y - points[i].y;
					c = a * points[i].y - b * points[i].x;
				}
				
				int count = 0;
				for (int k = 0; k < points.size(); k++) {
					if ((vSign == 1 && points[k].x == points[i].x) ||
						(vSign == 0 && a * points[k].y - b * points[k].x == c)) {
							count++;
					}
				}
				
				if (count > maxCount) {
					maxCount = count;
				}
			}
		}
		
		return maxCount;
	}
};

int main(void) {
	Solution* s = new Solution();
	Point p1;
	p1.x = 20;
	p1.y = 30;
	Point p2;
	p2.x = 20;
	p2.y = 32;
	Point p3;
	p3.x = 28;
	p3.y = 30;
	Point p4;
  p4.x = 40;
	p4.y = 60;
	Point p5;
	p5.x = 10;
	p5.y = 15;
	vector<Point> points;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	
	cout << "Solution 1: " << s->maxPoints1(points) << endl;
	
	delete s;
	return 0;
}


