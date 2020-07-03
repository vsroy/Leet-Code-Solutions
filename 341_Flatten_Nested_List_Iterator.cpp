/*Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.*/

#include<iostream>
#include<vector>


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const std::vector<NestedInteger> &getList() const;
};


class NestedIterator 
{
public:
	int index = 0;
	std::vector<int> resultVect;
	NestedIterator(std::vector<NestedInteger> &nestedList) 
	{
		flatten(nestedList);
	}

	void flatten(std::vector<NestedInteger> &nestedList)
	{
		for (NestedInteger e : nestedList)
		{
			if (e.isInteger())
				resultVect.push_back(e.getInteger());
			else
				flatten(e.getList());
		}
	}

	int next() 
	{
		if (!hasNext())
			return -1;
		else
			return resultVect[index++];
	}

	bool hasNext() 
	{
		return (index < resultVect.size());
	}
};


//Your NestedIterator object will be instantiated and called as such:

int main()
{
	/*
	NestedIterator i(nestedList);
	while (i.hasNext()) std::cout << i.next();
	*/
	return 0;
}
