#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//     (iterator) to each key in a hash map. 

/* This is an alternate solution
class LRUCache 
{
	//The queue that will hold the key
	list<pair<int,int>> lruList;
	unordered_map<int, list<pair<int,int>>::iterator> lruMap;
	int capacity;

public:
	LRUCache(int capacity) 
	{
		this->capacity = capacity;
	}

	int get(int key) 
	{
		if (lruMap.find(key) == lruMap.end())
			return -1;
		else
		{
			list<pair<int, int>>::iterator tempPair = lruMap[key];
			tempPair->second;
		}
	}

	void put(int key, int value) 
	{
		//If the element is not found in the map
		if (lruMap.find(key) == lruMap.end())
		{
			//The capacity has been reached
			if (lruList.size() == capacity)
			{
				//Will remove element from the back of the queue
				std::pair<int,int> tempPair = lruList.back();

				//Remove element form the back and insert into the front
				lruList.pop_back();

				//Erasing the element from the map
				lruMap.erase(tempPair.first);
			}
		}
		else
		{
			//Erase the key from the map
			lruList.erase(lruMap[key]);
		}

		lruList.push_front(make_pair(key,value));
		lruMap[key] = lruList.begin();
	}

	void Display()
	{
		for (auto i : lruList)
			std::cout << i.first << " ";
	}
};
*/

class LRUCache {
private:
	list<int> q;
	unordered_map<int, list<int>::iterator> ref;
	unordered_map<int, int> map;
	int size;
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		int ans = -1;
		if (map.find(key) != map.end()){
			q.erase(ref[key]);
			q.push_front(key);
			ref[key] = q.begin();
			ans = map[key];
			return ans;
		}
		else{
			return ans;
		}
	}

	void put(int key, int value) {
		if (map.find(key) == map.end()){
			if (map.size() == size){
				int last = q.back();
				q.pop_back();
				ref.erase(last);
				map.erase(last);
			}
		}
		else{
			q.erase(ref[key]);
		}
		q.push_front(key);
		ref[key] = q.begin();
		map[key] = value;
	}
};

int main()
{
	LRUCache cache(2);
	

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4
	return 0;
}