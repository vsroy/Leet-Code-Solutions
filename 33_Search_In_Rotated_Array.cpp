/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).*/

#include<iostream>
#include<vector>

class Solution 
{
public:

	int standardBinarySearch(std::vector<int>& nums, int start, int end, int key)
	{
		if (end < start)
			return -1;	/*Key does not exist*/

		int mid = start + (end - start) / 2;

		if (key == nums[mid])
			return mid;

		if (key > nums[mid])
			standardBinarySearch(nums, mid + 1, end, key);
		else
			standardBinarySearch(nums, start, mid - 1, key);
	}


	int findPivot(std::vector<int>& nums, int start, int end)
	{
		if (end < start)	/*Tree is not rotated*/
			return -1;

		if (end == start)
			return start;

		int mid = start + (end - start) / 2;

		if (mid < end && nums[mid] > nums[mid + 1])
			return mid;	/*Found the pivot*/

		if (mid > start && nums[mid] < nums[mid - 1])
			return mid + 1;

		if (nums[start] > nums[mid])
			return findPivot(nums, start, mid - 1);
		else
			return findPivot(nums, mid + 1, end);
	}

	int search(std::vector<int>& nums, int target) 
	{
		int pivot = findPivot(nums, 0, nums.size() - 1);

		if (pivot == -1)
			return standardBinarySearch(nums, 0, nums.size() - 1, target);

		if (nums[pivot] == target)
			return pivot;

		if (nums[0] <= target)
			return standardBinarySearch(nums, 0, pivot - 1, target);
		else
			return standardBinarySearch(nums, pivot + 1, nums.size() - 1, target);
	}
};

int main()
{
	std::vector<int> ipVect{5,1,3};
	Solution s1;
	std::cout << s1.search(ipVect, 1);
	return 0;
}