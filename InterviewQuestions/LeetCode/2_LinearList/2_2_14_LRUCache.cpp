/*************************************************************
* Design and implement a data structure for Least Recently Used (LRU) cache.
* It should support the following operations: get and set.
* get(key) - Get the value (will always be positive) of the key if the key
* exists in the cache, otherwise return -1.
* set(key, value) - Set or insert the value if the key is not already present.
* Where the cache reached its capacity, it should invalidate the least recently
* used item before inserting a new item.
*************************************************************/
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

/* Time: O(logn), Space: O(n) */
class LRUCache {
private:
	struct CacheNode {
		int key;
		int value;
		CacheNode(int k, int v) : key(k), value(v){}
	};
public:
	LRUCache(int c) : capacity(c) {
	}
	
	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end()) {
			return -1;
		}
		
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	
	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end()) {
			if (cacheList.size() == capacity) {
				cacheMap.erase(cacheList.end()->key);
				cacheList.pop_back();
			}
			
			cacheList.push_front(CacheNode(key,value));
			cacheMap[key] = cacheList.begin();
		} else {
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	int capacity;
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
};

int main(void) {
	LRUCache lruCache(10);
	
	for (int i = 0; i < 10; i++) {
		lruCache.set(i, i);
	}
	
	cout << "Original LRU Cahce: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << lruCache.get(i) << " ";
	}
	
	lruCache.set(11, 11);
	cout << endl << "Changed LRU Cahce: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << lruCache.get(i) << " ";
	}
}