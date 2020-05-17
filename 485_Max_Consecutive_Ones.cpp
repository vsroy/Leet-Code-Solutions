/*Given a binary array, find the maximum number of consecutive 1s in this array.*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	int findMaxConsecutiveOnes(std::vector<int>& nums) 
	{
		int maxOnesSoFar = 0;
		int counter = 0, currentOnes = 0;
		while (counter < nums.size())
		{
			if (nums[counter] == 0)
			{
				if (currentOnes > maxOnesSoFar)
				{
					maxOnesSoFar = currentOnes;
					currentOnes = 0;
				}
				else
					currentOnes = 0;
			}
			else
				currentOnes++;
			counter++;
		}
		if (currentOnes > maxOnesSoFar)
			maxOnesSoFar = currentOnes;
		return maxOnesSoFar;
	}
};

int main()
{
	Solution s1;
	std::vector<int> vectBinary{ 1, 1, 0, 1, 1, 1, 0,1,1,1,0,1,1,1 };
	std::cout << s1.findMaxConsecutiveOnes(vectBinary);
	return 0;
}