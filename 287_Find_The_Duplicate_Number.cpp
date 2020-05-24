/*Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	int findDuplicate(std::vector<int>& nums) 
	{
		/*Using Floyd Cycle Detection*/
		
		if (nums.size() <= 1)
			return 1;
		
		int fast = nums[nums[0]];
		int slow = nums[0];

		while (fast != slow)
		{
			/*Move one step for slow*/
			slow = nums[slow];

			/*Move one step for fast*/
			fast = nums[nums[fast]];
		}

		/*Now we know that fast and slow form a loop. We need to find the entry point of the cycle*/
		fast = 0;
		while (fast != slow)
		{
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;

		/*
		int totalElements = nums.size()-1;
		int elementSum = (totalElements*(totalElements+1)) / 2;

		int totalSum = 0;
		for (auto i : nums)
			totalSum += i;
		return (totalSum - elementSum);
		*/
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 3, 1, 3, 4, 2 };
	std::cout << s1.findDuplicate(ipVect);
	return 0;
}