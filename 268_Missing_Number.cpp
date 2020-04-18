/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.*/
#include<iostream>
#include<vector>

int missingNumber(std::vector<int>& nums)
{
	int totalSum = 0;
	int totalElements = nums.size()+1;
	std::vector<int>::iterator it;
	
	for (it = nums.begin(); it != nums.end(); it++)
		totalSum += *it;

	int expectedSum = (totalElements*(totalElements + 1)) / 2;
	expectedSum -= totalElements;

	return (expectedSum - totalSum);
}

int main()
{
	std::vector<int> sampleVect{ 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	std::cout << missingNumber(sampleVect);
	return 0;
}