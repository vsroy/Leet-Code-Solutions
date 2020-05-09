/*Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	long thirdMax(std::vector<int>& nums) 
	{
		/*Loop thorugh once to find the max number*/
		int maxNumber = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > maxNumber)
				maxNumber = nums[i];
		}

		/*Here we get the maximum element. Now run another loop to find the second largest number ignoring max*/

		long LargestNumber = LONG_MIN;
		long secondLargestNumber = LONG_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != maxNumber)
			{
				if (nums[i] > LargestNumber && nums[i] > secondLargestNumber)
				{
					long temp = LargestNumber;
					LargestNumber = nums[i];
					secondLargestNumber = temp;
				}
				else if (nums[i] > secondLargestNumber && nums[i] < LargestNumber)
					secondLargestNumber = nums[i];
			}
		}
		if (secondLargestNumber == LONG_MIN)
			return maxNumber;
		else
			return secondLargestNumber;

	}
};

int main()
{
	Solution s1;
	std::vector<int> nums{ 1,2 };
	std::cout << s1.thirdMax(nums);
	return 0;
}