#include<vector>
#include<iostream>
#include<algorithm>

class Solution 
{
public:
	int jump(std::vector<int>& nums) 
	{
		/*If size of vect is 1 or 0, we return 0 as number of jumps required to reach the end is 0, it is already at the end */
		if (nums.size() < 2)
			return 0;

		int maxi = nums[0], maxi2 = 0;

		/*This is just a helper looper variable*/
		int i = 0;

		/*This will store the result*/
		int count = 0;

		/*Looping the helper looper*/
		while (i <= maxi && i < nums.size())
		{
			count++;

			/*Looping i till max value of i can be reached*/
			for (; i <= maxi && i < nums.size(); i++)
			{
				/*Check all values till maxi. If jump from current position is furthest, then we set the value of maxi as that value*/
				maxi2 = std::max(maxi2, i + nums[i]);
			}
			maxi = maxi2;
		}
		return count;
	}
};


int main()
{
	std::vector<int> ipVect{2,3,1,1,4};
	Solution s1;
	std::cout << s1.jump(ipVect);
	return 0;
}