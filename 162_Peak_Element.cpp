/*A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.*/

#include<iostream>
#include<vector>


class Solution {
public:
	int findPeakElement(std::vector<int>& nums) {
		if (nums.size() == 0) return -1;
		if (nums.size() == 1) return 0;
		int low = 0;
		int high = nums.size() - 1;
		while (low<high) {
			int mid = low + (high - low) / 2;
			if (mid>0 && nums[mid] < nums[mid - 1]) { // Just Assume that if the left nebhouring element to the mid  is bigger than mid, its GURANTEED that there will be a peak in the left half.
				high = mid;
			}
			else if (nums[mid] < nums[mid + 1]) { //  // Just Assume that if the right nebhouring element to the mid  is bigger than mid, its GURANTEED that there will be a peak in the right half.
				low = mid + 1;
			}
			else {
				return mid; //You will land here ONLY when you're on a peak, i.e left element < mid element > right element
			}
		}
		return low;
	}
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{ 1, 2, 1, 3, 5, 6, 4 };
	std::cout << s1.findPeakElement(ipVect);
	return 0;
}