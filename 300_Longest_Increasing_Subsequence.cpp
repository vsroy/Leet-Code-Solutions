/*Given an unsorted array of integers, find the length of longest increasing subsequence.*/
#include<vector>
#include<iostream>
#include<algorithm>

class Solution 
{
public:
	int lengthOfLIS(std::vector<int>& nums) 
	{
		std::vector<int> dpVect(nums.size());

		if (nums.size() <= 1)
			return nums.size();
		
		/*Initializing all variables to 1*/
		for (int i = 0; i < dpVect.size(); i++)
		{
			dpVect[i] = 1;
		}

		/*Now looping through all the remaining elements of the dp vector*/
		for (int i = 1; i < dpVect.size(); i++)
		{
			/*Loop from the start till i and compare the values of the dpvect*/
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
					dpVect[i] = std::max(dpVect[i],dpVect[j]+1);
			}
		}
		int maxElement = dpVect[0];
		for (auto i : dpVect)
			maxElement = std::max(maxElement, i);
		return maxElement;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 10, 9, 2, 5, 3, 7, 101, 18 };
	std::cout << s1.lengthOfLIS(ipVect);
	return 0;
}