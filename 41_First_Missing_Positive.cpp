/*Given an unsorted integer array, find the smallest missing positive integer.*/
#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	int firstMissingPositive(vector<int>& nums) 
	{
		if (nums.empty())
			return 1;



		/*Vector tp mark the ocurrence of elements*/
		std::vector<bool> presentElement(nums.size() + 1);

		bool zeropresent = false;
		/*Mark the elements which are present in the vector*/
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0 && nums[i] <= nums.size())
				presentElement[nums[i]] = true;
			if (nums[i] == 0)
				zeropresent = true;
		}

		for (int i = 1; i <= nums.size(); i++)
		{
			if (presentElement[i] == false)
				return i;
		}
		return zeropresent ? (nums.size()) : (nums.size() + 1);
	}
};

int main()
{
	Solution s1;
	vector<int> ipVect = { 2 };
	std::cout << s1.firstMissingPositive(ipVect);
	return 0;
}