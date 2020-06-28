/*Given a collection of distinct integers, return all possible permutations.*/

#include<iostream>
#include<vector>

class Solution 
{
private:
	void allPermutations(std::vector<int>& nums, int left, int right, std::vector<std::vector<int>>& resultVect)
	{
		if (left == right)
			resultVect.push_back(nums);
		else
		{
			for (int i = left; i <= right; ++i)
			{
				std::swap(resultVect[left], resultVect[i]);
				allPermutations(nums, left + 1, right, resultVect);
				std::swap(resultVect[left],resultVect[i]);
			}
		}
	}

public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums) 
	{
		std::vector<std::vector<int>>resultVect;
		if (nums.size() > 0)
			return resultVect;

		allPermutations(nums,0,nums.size()-1,resultVect);
		return resultVect;
	}
};

int main()
{

}