/*Assume you are an awesome parent and want to give your children some cookies. 
But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that 
the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, 
and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int findContentChildren(std::vector<int>& g, std::vector<int>& s) 
	{
		std::sort(g.begin(), g.end());	/*Child vector*/
		std::sort(s.begin(), s.end());  /*Cookie vector*/

		int childCounter = 0;
		int cookieCounter = 0;
		int satisfiedChild = 0;
		while (cookieCounter < s.size() && childCounter < g.size())
		{
			if (g[childCounter] <= s[cookieCounter])
			{
				satisfiedChild++;
				childCounter++;
				cookieCounter++;
			}
			else
				cookieCounter++;
		}
		return satisfiedChild;
	}
};

int main()
{
	std::vector<int> childVector{1,2,3};
	std::vector<int> cookieVector{ 1, 2 };

	Solution s1;

	std::cout << s1.findContentChildren(childVector, cookieVector);
	return 0;
}