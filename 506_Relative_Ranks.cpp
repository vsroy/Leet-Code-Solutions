/*Given scores of N athletes, find their relative ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

class Solution 
{
public:

	bool ReverseSort(int a, int b)
	{
		return b > a;
	}

	std::vector<std::string> findRelativeRanks(std::vector<int>& nums) 
	{
		std::vector<int> numsTemp = nums;
		std::sort(numsTemp.begin(), numsTemp.end());
		std::reverse(numsTemp.begin(), numsTemp.end());
		std::map<int, std::string> rankMap;

		std::vector<std::string> resultVect;

		int i = 0;
		while (i < numsTemp.size())
		{
			if (i == 0)
				rankMap[numsTemp[i]] = "Gold Medal";

			else if (i == 1)
				rankMap[numsTemp[i]] = "Silver Medal";

			else if (i == 2)
				rankMap[numsTemp[i]] = "Bronze Medal";

			else
				rankMap[numsTemp[i]] = std::to_string(i + 1);
			i++;
		}

		for (int i : nums)
		{
			resultVect.push_back(rankMap[i]);
		}

		return resultVect;
	}
};

int main()
{
	std::vector<int> ipVect{10,3,8,9,4};
	Solution s1;
	std::vector<std::string> reverseVect = s1.findRelativeRanks(ipVect);

	for (std::string i : reverseVect)
		std::cout << i << " ";

	return 0;
}