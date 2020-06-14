/*Given a non-empty array of integers, return the k most frequent elements.*/

#include<vector>
#include<map>
#include<queue>
#include<iostream>

class Solution 
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
	{
		std::map<int, int> frequentMap;
		std::priority_queue<std::pair<int,int>> frequentQueue;
		std::vector<int> answer;
		
		/*Adding the vector elements to the map*/
		for (int i = 0; i < nums.size(); i++)
			frequentMap[nums[i]]++;

		/*Now, storing them in the priority queue one by one so that they will be sorted according to their occurrence*/
		std::map<int, int>::iterator it;
		
		for (it = frequentMap.begin(); it != frequentMap.end(); it++)
			frequentQueue.push(std::make_pair(it->second,it->first));

		int i = 0;
		while (i < k)
		{
			answer.push_back(frequentQueue.top().second);
			frequentQueue.pop();
			i++;
		}
		return answer;
	}
};


int main()
{
	std::vector<int> nums{ 1, 1, 1, 2, 2, 3 };
	Solution s1;
	std::vector<int> result = s1.topKFrequent(nums,2);
	for (auto i : result)
		std::cout << i << " ";
	return 0;
}