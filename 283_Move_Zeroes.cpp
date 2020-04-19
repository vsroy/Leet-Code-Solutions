/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.*/

#include<iostream>
#include<vector>

void moveZeroes(vector<int>& nums) {
	int x = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (i != x && nums[i] != 0) {
			nums[x++] = nums[i];
			nums[i] = 0;

		}
		if (i == x && nums[i] != 0)
			x++;
	}
}

int main()
{
	//std::vector<int> vect1{ 0, 1, 0, 3, 12 };
	std::vector<int> vect1{2,1};
	moveZeroes(vect1);
	std::vector<int>::iterator it;

	for (it = vect1.begin(); it != vect1.end(); it++)
		std::cout << *it;
	return 0;
}