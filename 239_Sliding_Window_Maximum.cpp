/*Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.*/

#include<iostream>
#include<vector>
#include<set>

class Solution 
{
public:
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
	{
		std::vector<int> resultSet;
		std::multiset<int> queueSet;
		int i = 0;
		
		/*Inserting the elements till k in the set*/
		while (i < k)
		{
			queueSet.insert(nums[i]);
			i++;
		}

		int low = 0, high = k - 1;
		while (high < nums.size())
		{
			resultSet.push_back(*queueSet.rbegin());	/*rbegin will give highest value in a set*/
			if (high == nums.size() - 1)
				break;
			queueSet.erase(queueSet.find(nums[low]));
			queueSet.insert(nums[high+1]);
			low++; high++;
		}
		return resultSet;
	}
};


int main()
{
	Solution s1;
	std::vector<int> ipVect{ 1, 3, -1, -3, 5, 3, 6, 7 };
	std::vector<int> resultVect = s1.maxSlidingWindow(ipVect,3);
	for (auto i : resultVect)
		std::cout << i << " ";
	return 0;
}