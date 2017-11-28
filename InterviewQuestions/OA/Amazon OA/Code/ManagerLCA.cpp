/*********************************************
* Given the association of the managers and employee, 
* find the nearest manager of them.
*********************************************/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
	string val;
	vector<TreeNode*> child;
	TreeNode(string v) : val(v), child({}) {}
};

class Solution {
private:
	TreeNode* buildTree(vector<pair<string, string>> associations) {
		if (associations.size() == 0) {
			return nullptr;
		}
		
		unordered_map<string, TreeNode*> m1;
		unordered_map<string, int> m2;
		for (auto as : associations) {
			if (m1.find(as.first) == m1.end()) {
				m1[as.first] = new TreeNode(as.first);
				m2[as.first] = 0;
			}
			
			if (m1.find(as.second) == m1.end()) {
				m1[as.second] = new TreeNode(as.second);
				m2[as.second] = 1;
			} else {
				m2[as.second]++;
			}
			
			m1[as.first]->child.push_back(m1[as.second]);
		}
		
		for (auto a : m2) {
			if (a.second == 0) {
				return m1[a.first];
			}
		}
	}
	
	bool findNodePath(TreeNode* node, vector<TreeNode*> &path, string value) {
		if (node == nullptr) {
			return false;
		}		

		if (node->val != value) {
			for (TreeNode* nn : node->child) {
				path.push_back(node);
				if (findNodePath(nn, path, value)) {
					return true;
				}
				
				path.pop_back();
			}
			
			return false;
		} else {
			return true;
		}
	}
	
	void outputTree(TreeNode* root) {
		queue<TreeNode*> level;
		
		level.push(root);
		
		while(!level.empty()) {
			queue<TreeNode*> nextLevel;
			while (!level.empty()) {
				TreeNode* node = level.front(); level.pop();
				cout << node->val << ", ";
				for (TreeNode* next : node->child) {
					nextLevel.push(next);
				}
			}
			
			level = nextLevel;
			cout << endl;
		}
		
		cout << endl;
	}
public:
	string getNearestManager(vector<pair<string, string>> associations, string node1, string node2) {
		TreeNode *root = buildTree(associations);
		
		//outputTree(root);
		vector<TreeNode*> left, right;
		left.push_back(root);
		right.push_back(root);
		bool vl = findNodePath(root, left, node1);
		bool vr = findNodePath(root, right, node2);

		if (!vl || !vr) {
			return "";
		}
		
		int i = 0;
		for (; i < left.size() && i < right.size(); i++) {
			if (left[i]->val != right[i]->val) {
				return left[i-1]->val;
			}
		}
		
		return i == left.size() || i == right.size() ? left[i-1]->val : "";
	}
};

int main(void) {
	Solution *s = new Solution();
	vector<pair<string, string>> associations = {
		{"A", "B"},
			{"B", "C"},
				{"C", "D"},
					{"D", "E"},
					{"D", "F"},
				{"C", "G"},
				{"C", "H"},
			{"B", "I"},
				{"I", "J"},
					{"J", "K"},
		{"A", "L"},
		{"A", "M"},
			{"M", "N"}
	};
	
	cout << "result for A, B: " << s->getNearestManager(associations, "A", "B") << endl;
	cout << "result for N, K: " << s->getNearestManager(associations, "N", "K") << endl;
	cout << "result for J, K: " << s->getNearestManager(associations, "J", "K") << endl;
	cout << "result for E, K: " << s->getNearestManager(associations, "E", "K") << endl;
	cout << "result for Z, K: " << s->getNearestManager(associations, "Z", "K") << endl;
	cout << "result for A, Z: " << s->getNearestManager(associations, "A", "Z") << endl;
	
	delete s;
	return 0;
}