/*Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.*/

#include<iostream>
#include<vector>
class Solution 
{
public:
	bool canJump(std::vector<int>& nums) //1 2 0 1
	{
		if (nums[0] == 0)
		{
			if (nums.size() > 1)
				return false;
			else
				return true;
		}

		int counter = 0;
		int currVal = nums[0];
		while (counter < nums.size())
		{
			if (counter == nums.size() - 1)	/*End of the array has been reached*/
				return true;
			
			if (currVal < nums[counter])
				currVal = nums[counter];
			
			if (currVal == 0)
			{
				if (nums[counter] == 0)
					return false;
				else
					currVal = nums[counter];
			}
			currVal--;
			/*
			if (currVal == 0 && nums[counter] == 0)
				return false;
			*/
			counter++;
			

		}
		return true;
	}
};

int main()
{
	Solution s1;
	//std::vector<int> ipVect{2,3,1,1,4};
	std::vector<int> ipVect{ 3,2,1,0,4 };
	//std::vector<int> ipVect{ 1,2,0,1 };
	std::cout << s1.canJump(ipVect);
	return 0;
}