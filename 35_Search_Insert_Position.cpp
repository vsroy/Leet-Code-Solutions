/*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.*/
#include<iostream>
#include<vector>

int searchInsert(std::vector<int>& nums, int target) 
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (target == nums[i])
			return i;
		else if (target < nums[i])
			return i;
	}
	return nums.size();
}

int main()
{
	std::vector<int> ipVect = { 1, 3, 5, 6 };
	std::cout << searchInsert(ipVect, 0);
	return 0;
}
