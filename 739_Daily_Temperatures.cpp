/*Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would 
have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].*/

#include<iostream>
#include<vector>
#include<stack>o

class Solution 
{
public:
	std::vector<int> dailyTemperatures(std::vector<int>& T) 
	{
		/*Storing the result in a vector*/
		std::vector<int> diffVect(T.size(),0);
		std::stack<int> tempStack;
		for (int i = 0; i < T.size(); i++)
		{
			if (tempStack.empty())
			{
				tempStack.push(i);
				continue;
			}

			/*Checking that the top of the stack should be less than the current element*/
			while (!tempStack.empty() && (T[tempStack.top()] < T[i]))
			{
				diffVect[tempStack.top()] = i - tempStack.top();
				tempStack.pop();
			}
			tempStack.push(i);
		}
		return diffVect;
	}
};


int main()
{
	Solution s1;
	std::vector<int> vectInt{ 73, 74, 75, 71, 69, 72, 76, 73 };
	std::vector<int> resultVect = s1.dailyTemperatures(vectInt);
	for (auto i : resultVect)
		std::cout << i << " ";
	return 0;
}