/*Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets 
such that the sum of elements in both subsets is equal.*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums, int index, int sum, int total, unordered_map<string, bool>& mp)
	{
		//Runtime = O(2^n) - take the number or don't take it
		//Space = O(N) - for the numbers we have

		//Now we need something to maintain the state

		string state = to_string(index) + to_string(sum);

		if (mp.find(state) != mp.end())
			return mp[state];

		// first check if the sub-array we have created has half of the total
		//if it has half of the total, just return true

		if (sum * 2 == total)
			return true;

		//now check for the false base cases

		//if the current sum exceeds half of the total or the index is not valid

		if (sum>total / 2 || index >= nums.size())
			return false;

		//now we just have to simulate taking and not taking the numbers to create the array

		//This shall lead to TLE - this is recursion and not DP - DP stores the array
		//we simulate not taking the number OR taking the number in the partition

		bool foundPartition = canPartition(nums, index + 1, sum + nums[index], total, mp) || canPartition(nums, index + 1, sum, total, mp);


		mp[state] = foundPartition;

		return foundPartition;

		// return canPartition(nums, index+1, sum, total) ||
		//         canPartition(nums, index+1, sum+nums[index], total);

	}
	bool canPartition(vector<int>& nums) {

		//https://www.youtube.com/watch?v=3N47yKRDed0

		//Just add the numbers and check whether it's odd or even

		//If it is odd, then there is no chance that there can be a partition
		//such that both the partitions are equal

		//odd+odd = even && even+even=even (odd sum is not possible)

		int sum = 0;

		for (auto num : nums)
		{
			sum += num;
		}

		if (sum % 2 != 0)
			return false;

		//now we call a helper function
		// the arguments are - the array itself, the current index, the current sum
		// and finally the total that we had already calculated

		//To solve the TLE issue, we use DP and use something that records the state of the problem

		unordered_map<string, bool> mp;

		return canPartition(nums, 0, 0, sum, mp);

	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 1, 5, 11, 5 };
	std::cout << s1.canPartition(ipVect);
	return 0;
}