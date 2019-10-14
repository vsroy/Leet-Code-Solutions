#include<iostream>
#include<set>
#include<vector>

int singleNumber(std::vector<int>& nums) 
{
	//Method 1 : Using XOR operation
	/*
	int ans = nums[0];
	for (int i = 1; i < nums.size(); i++)
		ans = ans ^ nums[i];
	return ans;
	*/

	//Method 2 : Using unique storage contianers like sets in C++ STL
	
	int vectSum = 0;
	int setSum = 0;
	std::set<int> ipSet;
	for (int i = 0; i < nums.size(); i++)
	{
		ipSet.insert(nums[i]);
		vectSum += nums[i];
	}

	std::set<int>::iterator it;
	for (it = ipSet.begin(); it != ipSet.end(); it++)
		setSum += *it;
	return ((2 * setSum) - vectSum);
	
}
int main()
{
	std::vector<int> ipVect{ 2,2,1 };
	std::cout << "The number which occurs only once in the vector is " << singleNumber(ipVect);
	return 0;
}