#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

class Solution 
{
public:
	int findKthLargest(std::vector<int>& nums, int k) 
	{
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		std::sort(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.end());
			return nums[k - 1];
	}
};

int main()
{

}