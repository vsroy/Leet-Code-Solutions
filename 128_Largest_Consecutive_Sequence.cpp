/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.*/

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution 
{
public:
	int longestConsecutive(std::vector<int>& nums) 
	{
		std::unordered_set<int> storageSet;

		/*Insert all elements into the storage set*/
		for (auto i : nums)
			storageSet.insert(i);


		int resultMaxVal = 0;
		/*Loop through all the elements in the hashset*/

		std::unordered_set<int>::iterator it;
		for (it = storageSet.begin(); it != storageSet.end(); it++)
		{
			int curVal = *it;
			int valSoFar = 1;

			/*We already have an element smaller than the current value, so ignoring this step*/
			if (storageSet.find(curVal - 1) != storageSet.end())
				continue;

			while (storageSet.find(curVal + 1) != storageSet.end())
			{
				valSoFar++;
				curVal++;
			}

			if (valSoFar > resultMaxVal)
				resultMaxVal = valSoFar;
		}
		return resultMaxVal;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 100, 4, 200, 1, 3, 2 };
	std::cout << s1.longestConsecutive(ipVect);
	return 0;
}