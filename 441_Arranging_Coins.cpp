/*You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.*/

#include<iostream>

class Solution 
{
public:
	int arrangeCoins(int n) 
	{
		if (n == 0)
			return 0;
		int totalStairs = 0, totalSum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (totalSum + i <= n)
			{
				totalSum += i;
				totalStairs++;
			}
			else
				break;
		}
		return totalStairs;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.arrangeCoins(5);
	return 0;
}