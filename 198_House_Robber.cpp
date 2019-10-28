#include<iostream>
#include<algorithm>
#include<vector>

int rob(std::vector<int>& nums) 
{
	int n = nums.size();
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return std::max(nums[0], nums[1]);
	
	int *resultArray = new int[n];	/*Creating the array of n integers*/
	resultArray[0] = nums[0];
	resultArray[1] = std::max(nums[0], nums[1]);

	for (int i = 2; i < n; i++)
		resultArray[i] = std::max((nums[i] + resultArray[i - 2]), resultArray[i - 1]);

	return resultArray[n-1];
}

int main()
{
	std::vector<int> ipVect{ 2, 7, 9, 3, 1 };
	std::cout << rob(ipVect);
	return 0;
}