/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.*/
#include<iostream>
#include<vector>

int maxSubArray(std::vector<int>& nums) 
{
	int maxSoFar = INT_MIN;
	int maxEndingHere = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		maxEndingHere = maxEndingHere + nums[i];
		if (maxEndingHere > maxSoFar)
			maxSoFar = maxEndingHere;

		if (maxEndingHere < 0)
			maxEndingHere = 0;
	}
	return maxSoFar;
}

int main()
{
	std::vector<int> sampleVect = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	std::cout << maxSubArray(sampleVect);
	return 0;
}