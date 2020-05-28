/*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.*/

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution 
{
public:
	int subarraySum(std::vector<int>& nums, int k) 
	{
		/*We create a map to store the current sum till that index*/
		std::unordered_map<int, int> sumMap;

		int sumSoFar = 0;
		int subArrays = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			sumSoFar += nums[i];

			if (sumSoFar == k)
				subArrays++;

			/*If a subarray exists matching the criteria*/
			if (sumMap.find(sumSoFar - k) != sumMap.end())
				subArrays += sumMap[sumSoFar - k];

			sumMap[sumSoFar]++;
		}
		return subArrays;
	}
};

int main()
{
	std::vector<int> ipVect{1,1,1};
	Solution s1;

	std::cout << s1.subarraySum(ipVect,2);
	return 0;
}