/*Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.*/

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> sampleVect;
	sampleVect.push_back(6);
	sampleVect.push_back(8);
	sampleVect.push_back(11);
	sampleVect.push_back(9);
	sampleVect.push_back(25);

	std::sort(sampleVect.begin(), sampleVect.end());

	for (auto i : sampleVect)
		std::cout << i << " ";

	int minVal = INT_MAX;

	for (int i = 0; i < sampleVect.size() - 1; i++)
	{
		int currMinVal = sampleVect[i + 1] - sampleVect[i];
		if (currMinVal < minVal)
			minVal = currMinVal;
	}

	return minVal;
}