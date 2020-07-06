/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.*/
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		vector<int> resultVect;
		int rows = matrix.size();
		int columns = matrix[0].size();
		int k = 0;	//Starting row index
		int l = 0;	//Starting column index

		int totalElements = rows*columns;

		while (k < rows && l < columns)
		{
			for (int i = l; i < columns; ++i)
				resultVect.push_back(matrix[k][i]);
			k++;	//Increment the row as we will not be travsersing top most row any more

			for (int i = k; i < rows; ++i)
				resultVect.push_back(matrix[i][columns-1]);
			columns--;	//Decrement the columns as we will not be traversing the right most column anymore

			if (k < rows)	/*Print the last remaining row*/
			{
				for (int i = columns - 1; i >= l; --i)
					resultVect.push_back(matrix[rows - 1][i]);
				rows--;		//Decrement the bottommost row as we will not be traversing this row anymore
			}

			if (l < columns)	/*Print the last remaining column*/
			{
				for (int i = rows - 1; i >= k; --i)
					resultVect.push_back(matrix[i][l]);
				l++;		//Decrement the leftmost columns as we will not be traversing this column anymore
			}

		}
		return resultVect;
	}
};

int main()
{
	Solution s1;
	vector<vector<int>> ipVect{ { 1, 2, 3, 4, 5, 6 },
	{ 7, 8, 9, 10, 11, 12 },
	{ 13, 14, 15, 16, 17, 18 } };
	
	vector<int> resultVect = s1.spiralOrder(ipVect);

	for (auto i : resultVect)
		std::cout << i << " ";
	
	return 0;
}