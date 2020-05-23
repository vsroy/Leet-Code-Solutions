/*Given a set of distinct integers, nums, return all possible subsets(the power set).
Note: The solution set must not contain duplicate subsets.
*/

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
	{
		std::vector<std::vector<int>> subsetVect;
		for (int i = 0; i < pow(2, nums.size()); i++)	/*For a vect with n numbers, we will have 2^n subsets, so generating a subset for each loop*/
		{
			std::vector<int> subsetPart;
			for (int j = 0; j < nums.size(); j++)
			{
				if (i & (1 << j))	/*Checks if the j-th bit the binary representation of i is set or not*/
					subsetPart.push_back(nums[j]); 
			}
			subsetVect.push_back(subsetPart);
		}
		return subsetVect;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{1,2,3};
	std::vector<std::vector<int>> subsetVect = s1.subsets(ipVect);
	for (int i = 0; i < subsetVect.size(); i++)
	{
		std::vector<int> subsetPart = subsetVect[i];
		for (int j = 0; j < subsetPart.size(); j++)
			std::cout << subsetPart[j] << " ";
		std::cout << std::endl;
	}
	return 0;
}