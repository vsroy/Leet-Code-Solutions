/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/

#include<iostream>
#include<vector>

class Solution
{
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
	{
		/*Base case*/
		if (matrix.size() == 0)
			return false;

		int rows = matrix.size();
		int columns = matrix[0].size();

		int i = 0; int j = columns - 1;
		
		/*Start with the top right corner*/
		while (i < rows && j >= 0)
		{
			/*If we get a match*/
			if (target == matrix[i][j])
				return true;

			/*If target is less than value of top most element of column, then it will also be less than all the remaining elements of column
			as column is in ascending order. We go to the left column*/
			else if (target < matrix[i][j])
				j--;

			/*If target is greater than value of top most element of column, then we will go down the column and check every row to find value*/
			else if (target > matrix[i][j])
				i++;
		}

		/*If we do not get a match*/
		return false;
	}
};

int main()
{
	return 0;
}