/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		return{ find_start(nums, target), find_end(nums, target) };
	}
	int find_start(vector<int> nums, int target){
		int l = 0;
		int r = nums.size() - 1;

		while (r - l >= 2){
			int mid = (l + r) / 2;
			if (nums[mid] == target && nums[mid - 1]<target){
				return mid;
			}
			if (nums[mid]<target){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		for (int i = l; i <= r; i++){
			if (nums[i] == target && i == 0){
				return 0;
			}
			else if (nums[i] == target && nums[i - 1] != target){
				return i;
			}
		}
		return -1;
	}
	int find_end(vector<int> nums, int target){
		int l = 0;
		int r = nums.size() - 1;

		while (r - l >= 2){
			int mid = (l + r) / 2;
			if (nums[mid] == target && nums[mid + 1]>target){
				return mid;
			}
			if (nums[mid] <= target){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		for (int i = l; i <= r; i++){
			if (nums[i] == target && i == nums.size() - 1){
				return i;
			}
			else if (nums[i] == target && nums[i + 1] != target){
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 5, 7, 7, 8, 8, 10 };
	std::vector<int> resultVect = s1.searchRange(ipVect, 6);

	for (int i : resultVect)
		std::cout << i << " ";
	return 0;
}