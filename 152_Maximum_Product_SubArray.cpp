/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	int maxProduct(std::vector<int>& nums) 
	{
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 0)
			return 0;
		int ans = nums[0];
		int mn = nums[0];
		int mx = nums[0];

		for (int i = 1; i<nums.size(); i++)
		{
			int temp = mx;

			mx = max(nums[i], max(nums[i] * mx, mn*nums[i]));
			mn = min(temp*nums[i], min(nums[i], mn*nums[i]));
			if (ans<mx)
				ans = mx;
		}

		return ans;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{-2,0,-1};

	std::cout << s1.maxProduct(ipVect);
	return 0;
}