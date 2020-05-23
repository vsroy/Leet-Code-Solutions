/*Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int findUnsortedSubarray(std::vector<int>& nums) 
	{
		/*
		if (nums.size() == 1)
			return 0;

		int startCounter = 0;
		int endCounter = nums.size() - 1;

		//For the pass from the start
		int numsSize = nums.size() - 2;
		while (startCounter <= numsSize)
		{
			if (nums[startCounter] > nums[startCounter + 1])
				break;
			startCounter++;
		}

		//For the pass from the end
		while (endCounter > 0)
		{
			if (nums[endCounter] < nums[endCounter - 1])
				break;
			endCounter--;
		}

		int size = 0;
		while (startCounter <= endCounter)
		{
			size++;
			startCounter++;
		}
		*/
		std::vector<int> tempNums = nums;

		/*Sorting the vector*/
		std::sort(tempNums.begin(), tempNums.end());

		int start = -1;
		int end = -1;

		for (int i = 0; i < tempNums.size(); i++)	/*Find the position of the vector from the start where it should be sorted but is not*/
			if (nums[i] != tempNums[i])
			{
				start = i;
				break;
			}

		for (int j = tempNums.size() - 1; j >= 0; j--)	/*Find the position of the vector from the end where it should be sorted but is not*/
			if (nums[j] != tempNums[j])
			{
				end = j;
				break;
			}

		if (start == -1 && end == -1)				/*Find the difference between the start and the end to find the length of the vector*/
			return 0;
		else
			return end - start + 1;
	}
};

int main()
{
	Solution s1;
	std::vector<int> iVect{ 2, 6, 4, 8, 10, 9, 15 };
	//std::vector<int> iVect{ 1 };
	//std::vector<int> iVect{ 1,2,3,4 };
	//std::vector<int> iVect{ 1, 2};
	std::cout << s1.findUnsortedSubarray(iVect);
	return 0;
}