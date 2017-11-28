/*************************************************
* Find top K ranking related movies except node itself
*************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Movie {
private:
	int id;
	float rate;
	vector<Movie*> similarMovies;
public:
	int getID() {
		return id;
	}
	float getRate() {
		return rate;
	}
	vector<Movie*> getSimilar() {
		return similarMovies;
	}
	void setSimilar(vector<Movie*> sms) {
		similarMovies = sms;
	}
	
	Movie(int id, float rate) {
		this->id = id;
		this->rate = rate;
	}
};

class MyComparator {
public:
	int operator() (Movie* &p1, Movie* &p2) {
		return p1->getRate() > p2->getRate();
	}
};

class Solution {
public:
	vector<Movie*> find(Movie& movie, int N) {
		priority_queue<Movie*, vector<Movie*>, MyComparator> q;
		unordered_map<int, bool> visited;
		vector<Movie*> res;
		
		visited[movie.getID()] = true;
		for (auto nextMovie : movie.getSimilar()) {
			if (visited[nextMovie->getID()]) {
				continue;
			}

			visited[nextMovie->getID()] = true;
			if (q.size() == N) {
				Movie *m = q.top();
				if (m->getRate() < nextMovie->getRate()) {
					q.pop();
					q.push(nextMovie);
				}
			} else {
				q.push(nextMovie);
			}
		}
		
		while (!q.empty()) {
			res.push_back(q.top());
			q.pop();
		}
		
		return res;
	}
};

int main(void) {
	Solution *s = new Solution();
	Movie* m1 = new Movie(1, 1);
	Movie* m2 = new Movie(2, 2);
	Movie* m3 = new Movie(3, 3);
	Movie* m4 = new Movie(4, 4);
	Movie* m5 = new Movie(5, 5);
	Movie* m6 = new Movie(6, 6);
	Movie* m7 = new Movie(7, 7);
	
	m1->setSimilar({m2, m3, m4, m6});
	m2->setSimilar({m1, m3, m4, m6});
	m3->setSimilar({m1, m2, m4, m6});
	m4->setSimilar({m1, m2, m3, m6});
	m6->setSimilar({m1, m2, m3, m4});
	
	vector<Movie*> res = s->find(*m6, 2);
	cout << "result: ";
	for (auto m : res) {
		cout << m->getID() << ",";
	}
	
	delete s;
	return 0;
}