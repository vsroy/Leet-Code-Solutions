/*Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.*/
#include<iostream>
#include<vector>

int removeDuplicates(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;
	int runner = 0;
	std::vector<int>::iterator it = nums.begin();
	while (it != (nums.end()-1))
	{
		if (*it == *(it + 1))
			nums.erase(it + 1);
		else
			it++;
	}
	return nums.size();
}

int main()
{
	std::vector<int> arrVect = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	std::cout << removeDuplicates(arrVect);
	return 0;
}