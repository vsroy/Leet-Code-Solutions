/*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.*/
#include<iostream>
#include<vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) 
{
	int start = 0;
	int end = numbers.size() - 1;
	while ((numbers[start] + numbers[end]) != target)
	{
		int currentSum = numbers[start] + numbers[end];
		if (currentSum < target)
			start++;
		else
			end--;
	}
	std::vector<int> resultVect{start+1,end+1};
	return resultVect;
}

int main()
{
	std::vector<int> ipVect{ 2, 7, 11, 15 };
	std::vector<int> resultVect = twoSum(ipVect, 9);
	for (int i = 0; i < resultVect.size(); i++)
		std::cout << resultVect[i] << " ";
	return 0;
}