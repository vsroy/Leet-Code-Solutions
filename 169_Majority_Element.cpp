#include<iostream>
#include<vector>
#include<algorithm>

int majorityElement(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	int vectSize = nums.size();
	int midElement = (vectSize / 2);
	return nums[midElement];
}

int main()
{
	std::vector<int> ipVect{ 3,3,4};
	std::cout << majorityElement(ipVect);
	return 0;
}