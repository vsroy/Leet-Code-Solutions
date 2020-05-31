/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int trap(std::vector<int>& height) 
	{
		if (height.empty())
			return 0;

		int totalSize = height.size();
		
		/*left array will store the tallest height bar to the left of the current element including itself*/
		int *left = new int[totalSize];

		/*left array will store the tallest height bar to the right of the current element including itself*/
		int *right = new int[totalSize];

		int resultWater = 0;

		/*Fill the left array*/
		left[0] = height[0];

		for (int i = 1; i < totalSize; i++)
			left[i] = std::max(left[i - 1], height[i]);

		/*Fill the right array*/
		right[totalSize - 1] = height[totalSize - 1];

		for (int i = totalSize - 2; i >= 0; i--)
			right[i] = std::max(right[i + 1], height[i]);

		/*Calculate the water at each level that will be minimum of left and right height values*/
		for (int i = 0; i < totalSize; i++)
			resultWater += std::min(left[i], right[i]) - height[i];

		return resultWater;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	std::cout << s1.trap(ipVect);
	return 0;
}