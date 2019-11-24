/*Given an array of integers, find if the array contains any duplicates.*/

#include<iostream>
#include<vector>
#include<set>

bool containsDuplicate(std::vector<int>& nums) 
{
	std::set<int> duplicateSet;
	for (int i = 0; i < nums.size(); i++)
	{
		if (duplicateSet.find(nums[i]) != duplicateSet.end())
			return true;
		else
			duplicateSet.insert(nums[i]);
	}
	return false;
}

int main()
{
	std::vector<int> duplicateVector{ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	std::cout << containsDuplicate(duplicateVector);
	return 0;
}
