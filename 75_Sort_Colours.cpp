/*Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: You are not suppose to use the library's sort function for this problem.*/

#include<iostream>
#include<vector>

class Solution 
{
public:

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void sortColors(std::vector<int>& nums) 
	{
		int start = 0, end = nums.size()-1;
		int startIndex = 0;
	
		while (startIndex <= end)
		{
			if (nums[startIndex] == 2 && startIndex != end)
			{
				swap(nums[startIndex],nums[end]);
				end--;
			}
			else if (nums[startIndex] == 0 && startIndex != start)
			{
				swap(nums[startIndex], nums[start]);
				start++;
			}
			else
			{
				startIndex++;
			}
		}
	}
};

int main()
{
	Solution s1;

	std::vector<int> ipVect{ 2, 0, 2, 1, 1, 0 };

	s1.sortColors(ipVect);

	for (int i : ipVect)
		std::cout << i << " ";
	return 0;
}