/*Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	bool increasingTriplet(vector<int>& nums) 
	{
		vector<int> resVect(nums.size());
		
		for (int i = 0; i < nums.size(); i++)
			resVect[i] = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if ((nums[i] > nums[j]) && ((resVect[j] + 1) > resVect[i]))
					resVect[i] = resVect[j]+ 1;
				if (resVect[i] == 3)
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s1;
	vector<int> ipVect{ 5,4,3,2,1};
	std::cout << s1.increasingTriplet(ipVect);
	return 0;
}