/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector <vector<int> > res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i< (int)nums.size() - 2; i++){
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])){
				int low = i + 1;
				int high = nums.size() - 1;
				int sum = 0 - nums[i];
				while (low < high){
					if (nums[low] + nums[high] == sum)// perfect case
					{
						res.push_back({ nums[i], nums[low], nums[high] });
						while (low < high && nums[low] == nums[low + 1]) low++;
						while (low < high && nums[high] == nums[high - 1]) high--;
						low++;
						high--;
					}
					else if (nums[low] + nums[high] > sum){
						high--;
					}
					else{
						low++;
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s1;
	//std::vector<int> ipVect{ -1, 0, 1, 2, -1, -4 };
	std::vector<int> ipVect{ -2, 0, 1, 1, 2 };
	std::vector < std::vector<int> > reVect = s1.threeSum(ipVect);

	for (auto i : reVect)
	{
		for (int j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}