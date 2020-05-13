/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums) 
	{
		vector<int> ans;
		for (int i = 0; i<nums.size(); ++i){
			if (nums[i]>0){
				if (nums[nums[i] - 1]>0)
					nums[nums[i] - 1] *= -1;
			}
			else{
				int index = -1 * nums[i];
				if (nums[index - 1]>0){
					nums[index - 1] *= -1;
				}
			}
		}
		for (int i = 0; i<nums.size(); ++i){
			if (nums[i]>0)
				ans.push_back(i + 1);
		}
		return ans;
	}
};

int main()
{
	Solution s1;
	//std::vector<int> ipVector = { 4, 3, 2, 7, 8, 2, 3, 1 };
	std::vector<int> ipVector = { 1,1,2,2 };
	std::vector<int> disappearedNumbers = s1.findDisappearedNumbers(ipVector);
	for (int i = 0; i < disappearedNumbers.size(); i++)
		std::cout << disappearedNumbers[i] << " ";
	return 0;
}