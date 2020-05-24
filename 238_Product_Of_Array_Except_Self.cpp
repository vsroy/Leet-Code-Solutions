/*Given an array nums of n integers where n > 1,  
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) 
	{
		int n = nums.size();
		int* leftArray = new int[nums.size()];	
		int *rightArray = new int[nums.size()];

		std::vector<int> prodVect;

		/*Construct the array which will hold the products of the elements from left*/
		leftArray[0] = 1;	/*This will always be 1*/
		for (int i = 1; i < n; i++)
			leftArray[i] = leftArray[i - 1] * nums[i - 1];

		/*Construct the array which will hold the products of the elements from right*/
		rightArray[n - 1] = 1; /*This will always be 1*/
		for (int j = n - 2; j >= 0; j--)
			rightArray[j] = rightArray[j + 1] * nums[j + 1];
		
		/*Finally, if we multiply the products of the arrays for each position, we will get the answer*/
		for (int k = 0; k < n; k++)
			prodVect.push_back(leftArray[k] * rightArray[k]);

		return prodVect;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{1,2,3,4};
	std::vector<int> ansVect = s1.productExceptSelf(ipVect);

	for (auto i : ansVect)
		std::cout << i << " ";

	return 0;
}