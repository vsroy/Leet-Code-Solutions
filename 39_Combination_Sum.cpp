/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations 
in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	void FindElements(std::vector<int>& candidates,
					  std::vector<std::vector<int>> &resultVector, 
					  std::vector<int> &subVector, 
					  int sum, int index)
	{
		if (sum < 0)
			return;

		if (sum == 0)
		{
			resultVector.push_back(subVector);
			return;
		}

		/*For all the values that are smaller than sum ,use recursion*/
		while (index < candidates.size() && (sum - candidates[index] >= 0))
		{
			subVector.push_back(candidates[index]);	/*Consider the current element in the result vector*/

			/*Use recursion to find if this vector fits*/
			FindElements(candidates,resultVector,subVector,sum-candidates[index],index);
			index++;

			/*Using backtracking, check the vector*/
			subVector.pop_back();
		}
	}

	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
	{
		//First sort the vector
		std::sort(candidates.begin(), candidates.end());
		
		//Then remove the duplicates
		candidates.erase(std::unique(candidates.begin(),candidates.end()), candidates.end());

		std::vector<int> subVector;
		std::vector<std::vector<int>> resultVector;

		FindElements(candidates,resultVector,subVector,target,0);

		return resultVector;
	}
};

int main()
{
	std::vector<int> ipVect{2,3,6,7};
	Solution s1;
	std::vector<std::vector<int>> answer = s1.combinationSum(ipVect,7);

	for (int i = 0; i < answer.size(); i++)
	{
		for (auto j : answer[i])
			std::cout << j << " ";
		std::cout << std::endl;
	}
	return 0;
}