/*You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
If it does not exist, output -1 for this number.*/

#include<iostream>
#include<vector>

class Solution
{
public:
	std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int> nextGreaterElement;				//4,1,2
		for (int i = 0; i < nums1.size(); i++)				//1 3 4 2
		{
			int currentElement = nums1[i];
			std::vector<int>::iterator it = std::find(nums2.begin(), nums2.end(), currentElement);
			if (it != nums2.end())
			{
				int currentElement = *it;
				while (it != nums2.end())
				{
					if (*it > currentElement)
					{
						nextGreaterElement.push_back(*it);
						break;
					}
					it++;
				}
					if (it == nums2.end())
						nextGreaterElement.push_back(-1);
			}
			else
				std::cout << "Element not present in the other vector";
		}
		return nextGreaterElement;
	}
};


int main()
{
	Solution s1;
	std::vector<int> nums1{2,4};
	std::vector<int> nums2{ 1,2,3,4};
	std::vector<int> answer = s1.nextGreaterElement(nums1, nums2);

	for (int i = 0; i < answer.size(); i++)
		std::cout << answer[i] << " ";
	return 0;
}