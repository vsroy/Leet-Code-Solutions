/*Given an array nums and a value val, remove all instances of that value in-place and return the new length.*/
#include<iostream>
#include<vector>

int removeElement(std::vector<int>& nums, int val) 
{
	if (nums.empty())
		return 0;

	std::vector<int>::iterator it1 = nums.begin();
	while ((nums.size() > 0) && *(nums.begin()) == val)
	{
		nums.erase(it1);
		it1 = nums.begin();
	}

	while ((nums.size() > 0) && it1 != (nums.end() - 1))
	{
		if (val == *(it1 + 1))
			nums.erase(it1 + 1);
		else
			it1++;
	}

	return nums.size();
}

int main()
{
	std::vector<int> ipVect = { 0, 1, 2, 2, 3, 0, 4, 2 };
	//std::vector<int> ipVect = { 3,2,2,3 };
	std::cout << removeElement(ipVect, 2);
	return 0;
}