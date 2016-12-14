/******************************************************
* There are N gas stations along a circular route, where the amount of gas at station
* i is gas[i].
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from
* station i to its next station(i + 1). You begin the journey with an empty tank at one
* of the gas stations.
* Return the starting gas stations's index if you can travel around the circuit once,
* otherwise return -1.
* Note: The solution is guarantee to be unique.
******************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* Time: O(n), Space: O(1) */
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int total = 0;
		int validSum = 0;
		int validStart = -1;
		for (int i = 0; i < gas.size(); i++) {
			validSum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (validSum < 0) {
				validSum = 0;
				validStart = i;
			}
		}
		
		return total >= 0 ? validStart + 1 : -1;
	}
};

int main(void) {
	Solution* s = new Solution();
	vector<int> gas = { 1, 1, 2, 1, 1, 1, 1, 2, 1, 1 };
	vector<int> cost = { 1, 2, 1, 1, 1, 2, 1, 1, 1, 1 };
	
	cout << "Solution: " << s->canCompleteCircuit(gas, cost) << endl;
	 
	delete s;
	return 0;
}