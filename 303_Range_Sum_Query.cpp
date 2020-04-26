/*Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.*/

#include<iostream>
#include<vector>

class NumArray {
private:
	std::vector<int> vectNums;
public:
	NumArray(std::vector<int>& nums) 
	{
		vectNums = nums;
	}

	int sumRange(int i, int j) 
	{
		int sum = 0;
		for (int iter = i; iter <= j; iter++)
			sum += vectNums[iter];
		return sum;
	}
};

int main()
{
	std::vector<int> nums{ -2, 0, 3, -5, 2, -1 };
	NumArray* obj = new NumArray(nums);
	int param_1 = obj->sumRange(0,5);
	std::cout << param_1;
	return 0;
}
