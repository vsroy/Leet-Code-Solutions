#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<iterator>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> vectMap;

		for (int i = 0; i < nums.size(); i++)
		{
			if (vectMap.count(target - nums[i]) != 0)
			{
				return{vectMap[target-nums[i]], i};
				vectMap[nums[i]] = i;
			}
		}
		return{};
	}
};

int main()
{
	vector<int> vect1 = { 3,3 };
	Solution s1;
	vector<int> vectAns = s1.twoSum(vect1, 6);
	for (auto i : vectAns)
		cout << i << " ";
	return 0;
}