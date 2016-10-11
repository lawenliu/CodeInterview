/*************************************
* Clone an undirected graph. Each node in the greaph contains a label and a list of its neighbours.
* OJ's undirected graph serialization: Nodes are labeled uniquely.
* We use # as a separator for each node, and , as a seperator for node label and each neighbour of 
* the node. As an example, consider the serialized graph {0, 1, 2#1, 2#2, 2}.
* The graph has a total of three nodes, and therefore contains three parts as separated by #.
* 1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
* 2. Second node is labeled as 1. Connect node 1 to node 2.
* 3. Third node is labeled as 2. Connect node 2 to node 2 (itself0), this forming a self-cycle.
* Visually, the graph looks like the following:
*       1
*      / \
*     /   \
*    0-----2
*         / \
*         \_/
*************************************/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
	UndirectedGraphNode* cloneGraph1Aux(const UndirectedGraphNode* node,
		unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> &copy) {
		if (copy.find(node) != copy.end()) {
			return copy[node];
		}
			
		UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
		copy[node] = newNode;
		for (int i = 0; i < node->neighbors.size(); i++) {
			UndirectedGraphNode* neighbor = cloneGraph1Aux(node->neighbors[i], copy);
			newNode->neighbors.push_back(neighbor);
		}
		
		return newNode;
	}
public:
	/* DFS, Time: O(n), Space: O(n) */
	UndirectedGraphNode* cloneGraph1(const UndirectedGraphNode* node) {
		if (node == NULL) {
			return NULL;
		}
		
		unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copy;
		cloneGraph1Aux(node, copy);
		
		return copy[node];
	}
	
	UndirectedGraphNode* cloneGraph2(const UndirectedGraphNode* node) {
		if (node == NULL) {
			return NULL;
		}
		
		unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copy;
		queue<const UndirectedGraphNode*> q;
		q.push(node);
		copy[node] = new UndirectedGraphNode(node->label);
		while (!q.empty()) {
			const UndirectedGraphNode* cur = q.front();
			q.pop();
			for (int i = 0; i < cur->neighbors.size(); i++) {
				UndirectedGraphNode* nbr = cur->neighbors[i];
				if (copy.find(nbr) != copy.end()) {
					copy[cur]->neighbors.push_back(copy[nbr]);
				} else {
					UndirectedGraphNode* newNode = new UndirectedGraphNode(nbr->label);
					copy[nbr] = newNode;
					copy[cur]->neighbors.push_back(newNode);
					q.push(nbr);
				}
			}
		}
		
		return copy[node];
	}
	
	void outputGraph(const UndirectedGraphNode* node) {
		queue<const UndirectedGraphNode*> q;
		unordered_set<const UndirectedGraphNode*> s;
		q.push(node);
		s.insert(node);
		while (!q.empty()) {
			const UndirectedGraphNode* cur = q.front();
			q.pop();
			cout << cur->label;
			for (int i = 0; i < cur->neighbors.size(); i++) {
				UndirectedGraphNode* nbr = cur->neighbors[i];
				cout << "," << nbr->label;
				if (s.find(nbr) == s.end()) {
					q.push(nbr);
					s.insert(nbr);
				}
			}
			
			if (!q.empty()) {
				cout << "#";
			}
		}
		
		cout << endl;
	}
	
	void deleteGraphAux(const UndirectedGraphNode* node, unordered_set<const UndirectedGraphNode*> &s) {
		s.insert(node);
		for (int i = 0; i < node->neighbors.size(); i++) {
			const UndirectedGraphNode* nbr = node->neighbors[i];
			if (s.find(nbr) == s.end()) {
				deleteGraphAux(nbr, s);
			}
		}
	}
	
	void deleteGraph(const UndirectedGraphNode* node) {
		unordered_set<const UndirectedGraphNode*> q;
		deleteGraphAux(node, q);
		unordered_set<const UndirectedGraphNode*>::iterator it;
		for (it = q.begin(); it != q.end(); it++) {
			const UndirectedGraphNode* node = *it;
			delete node;
		}		
	}
};

int main(void) {
	Solution* s = new Solution();
	UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
	node0->neighbors.push_back(node1);
	node0->neighbors.push_back(node2);
	node1->neighbors.push_back(node2);
	node2->neighbors.push_back(node2);
	
	UndirectedGraphNode* result1 = s->cloneGraph1(node0);
	UndirectedGraphNode* result2 = s->cloneGraph2(node0);
	
	cout<< "Solution: " << endl;
	s->outputGraph(result1);
	s->outputGraph(result2);
	
	cout << "Deleted" << endl;
	//Delete all the nodes.
	s->deleteGraph(node0);
	s->deleteGraph(result1);
	s->deleteGraph(result2);
	
	delete s;
	return 0;
}
