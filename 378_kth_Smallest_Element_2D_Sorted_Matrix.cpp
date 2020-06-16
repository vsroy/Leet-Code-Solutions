/*Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

class Solution 
{
public:
	int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
	{
		std::vector<int> resultVect;
		
		/*Append each vector one after the other from the 2D matrix array*/
		for (int i = 0; i < matrix.size(); i++)
		{
			std::vector<int> tempVect = matrix[i];
			std::copy(tempVect.begin(), tempVect.end(), std::back_inserter(resultVect));
		}

		std::sort(resultVect.begin(), resultVect.end());

		for (auto i : resultVect)
			std::cout << i << " ";
		
		return resultVect[k - 1];
	}
};

int main()
{
	Solution s1;

	std::vector<int> vect1{ 1,2};
	std::vector<int> vect2{ 1,3};

	std::vector<std::vector<int>> sampleVect{vect1,vect2};
	std::cout << s1.kthSmallest(sampleVect,2);
	return 0;
}