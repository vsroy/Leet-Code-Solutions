/*Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

class Solution 
{
public:
	int findPairs(std::vector<int>& nums, int k) 
	{
		/*
		std::set<int> sampleSet(nums.begin(), nums.end());
		nums.assign(sampleSet.begin(), sampleSet.end());
		*/
		std::sort(nums.begin(), nums.end());
		
		for (auto i : nums)
			std::cout << i << " ";
		
		std::map<int, int> resultMap;

		std::cout << std::endl;

		int diffCounter = 0;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			int currNumber = nums[i];
			
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] - nums[i] == k)
				{
					resultMap.insert(std::pair<int, int>(nums[i], nums[j]));
					break; 
				}
			}
		}
		return resultMap.size();
	}
};

int main()
{
	Solution s1;

	std::vector<int> sampleVect{ 1, 2, 3, 4, 5 };
	std::cout << s1.findPairs(sampleVect, 1);
	return 0;
}