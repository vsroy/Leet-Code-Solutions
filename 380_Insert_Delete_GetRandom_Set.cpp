#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>

class RandomizedSet 
{
public:

	std::set<int> randSet;
	std::vector<int> randVect;

	/** Initialize your data structure here. */
	RandomizedSet() 
	{
		std::srand(std::time(0));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) 
	{
		if (randSet.find(val) == randSet.end())
		{
			randSet.insert(val);
			randVect.push_back(val);
			return true;
		}
		else
			return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) 
	{
		if (randSet.find(val) != randSet.end())
		{
			randSet.erase(val);
			std::vector<int>::iterator it = std::find(randVect.begin(),randVect.end(),val);
			randVect.erase(it);
			return true;
		}
		else
			return false;
	}

	/** Get a random element from the set. */
	int getRandom() 
	{
		int r = std::rand() % randVect.size() + 1;
		return randVect[r];
	}
};

int main()
{
	RandomizedSet randomSet;
	randomSet.insert(1);

	randomSet.remove(2);

	randomSet.insert(2);

	std::cout << randomSet.getRandom();

	randomSet.remove(1);

	randomSet.insert(2);

	std::cout << randomSet.getRandom();

	return 0;
}