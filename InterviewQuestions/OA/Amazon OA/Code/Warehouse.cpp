/**********************************
* Find nearest warehouse based on the position to {0, 0}
**********************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class WareHouse {
public:
	double distance;
	pair<int, int> point;
	
	WareHouse(int d, pair<int, int> p) : distance(d), point(p) {}
};

class MyComparator {
public:
	int operator() (WareHouse* &p1, WareHouse* &p2) {
		return p1->distance < p2->distance;
	}
};

class Solution {
public:
	vector<pair<int, int>> getNearest(vector<pair<int, int>> nodes, int k) {
		vector<pair<int, int>> result;
		priority_queue<WareHouse*, vector<WareHouse*>, MyComparator> q;
		
		for (auto node : nodes) {
			double d = sqrt(pow(node.first, 2) + pow(node.second, 2));
			if (q.size() >= k) {
				if (!q.empty() && q.top()->distance > d) {
					q.pop();
					q.push(new WareHouse(d, node));
				}
			} else {
				q.push(new WareHouse(d, node));
			}
		}
		
		while (!q.empty()) {
			auto t = q.top();
			q.pop();
			result.push_back(t->point);
		}
		
		return result;
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<pair<int, int>> nodes = {
		{3, 2},
		{2, 3},
				{4, 5},
					{5, 6},
						{8, 9},
							{1, 2},
								{10, 11}
	};
	
	vector<pair<int, int>> result = s->getNearest(nodes, 3);
	for (auto node : result) {
		cout << node.first << ", " << node.second << endl;
	}
	
	delete s;
	return 0;
}

