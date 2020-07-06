/*Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Alternate solution
/*
class Solution 
{
public:

	
	void swapElements(int& a, int&  b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void wiggleSort(vector<int>& nums) 
	{
		bool lessthan = true;
		for (int i = 0; i < nums.size()-1; i++)
		{
			if (lessthan)
			{
				if (nums[i] > nums[i + 1])
					swapElements(nums[i],nums[i + 1]);
			}
			else
			{
				if (nums[i] < nums[i + 1])
					swapElements(nums[i], nums[i + 1]);
			}
			lessthan = !lessthan;
		}
	}
	*/

	class Solution {
	public:
		void wiggleSort(vector<int>& nums) {
			int n = nums.size();
			int mid = n / 2;
			nth_element(nums.begin(), nums.begin() + mid, nums.end());
			threeWayPartition(nums, nums[mid]);
			vector<int> res(n);
			int largeStart = n - 1;
			int smallStart = (n % 2) ? mid : (mid - 1);
			for (int i = 0; i < n; i += 2)
				res[i] = nums[smallStart--];
			for (int i = 1; i < n; i += 2)
				res[i] = nums[largeStart--];
			nums = res;
		}

		// this ensures all values equal to the median is in the middle
		void threeWayPartition(vector<int> &nums, int val) {
			int i = 0, j = 0;
			int n = nums.size() - 1;
			while (j <= n){
				if (nums[j] < val)
					swap(nums[i++], nums[j++]);
				else if (nums[j] > val)
					swap(nums[j], nums[n--]);
				else
					j++;
			}
		}
};


int main()
{
	Solution s1;
	vector<int> ipVect{ 1, 3, 2, 2, 3, 1 };
	s1.wiggleSort(ipVect);
	for (auto i : ipVect)
		std::cout << i << " ";
	return 0;
}