/*Given a collection of intervals, merge all overlapping intervals.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution 
{
public:

	static bool CompareIntervals(std::vector<int>& vect1, std::vector<int>& vect2)
	{
		return (vect1[0] < vect2[0]);
	}

	std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) 
	{
		sort(intervals.begin(), intervals.end(), CompareIntervals);
		/*
		for (auto i : intervals)
		{
			for (int element : i)
			{
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
		*/

		/*Create a stack to store the resultant intervals*/
		std::stack<vector<int>> resultantStack;
		resultantStack.push(intervals[0]);

		for (int i = 1; i < intervals.size(); i++)
		{
			vector<int> current = intervals[i];
			vector<int> top = resultantStack.top();

			if (top[1] < current[0])
				resultantStack.push(current);
			else if (top[1] < current[1])
			{
				top[1] = current[1];
				resultantStack.pop();
				resultantStack.push(top);
			}
		}

		std::vector<std::vector<int>> resultVect;
		while (!resultantStack.empty())
		{
			resultVect.push_back(resultantStack.top());
			resultantStack.pop();
		}

		reverse(resultVect.begin(), resultVect.end());

		return resultVect;
	}
};

int main()
{
	Solution s1;
	std::vector<std::vector<int>> intervals{ {1,3},{8,10},{2,6},{15,18} };
	std::vector<std::vector<int>> answer = s1.merge(intervals);

	for (auto i : answer)
	{
		for (int element : i)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}