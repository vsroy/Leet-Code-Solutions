/*Given a non-empty integer array of size n, find the minimum number of moves 
required to make all array elements equal, where a move is incrementing n - 1 elements by 1.*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	int minMoves(std::vector<int>& nums) 
	{
		long long totalSum = 0, min = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			totalSum += nums[i];
			if (nums[i] < min)
				min = nums[i];
		}
		return (totalSum - min*nums.size());
	}
};

int main()
{
	Solution s1;
	std::vector<int> sampleVect{1,2,3};
	std::cout << s1.minMoves(sampleVect);
	return 0;
}