/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int maxArea(std::vector<int>& height) 
	{
		int start = 0;
		int end = height.size() - 1;

		int area = INT_MIN;

		while (start < end)
		{
			int localArea = std::min(height[start], height[end]) * (end - start);
			
			if (localArea > area)
				area = localArea;

			if (height[start] < height[end])
				start++;
			else
				end--;

		}
		return area;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	std::cout << s1.maxArea(ipVect);
	return 0;
}
