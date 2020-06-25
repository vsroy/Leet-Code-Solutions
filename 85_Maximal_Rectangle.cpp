/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	int maximalRectangle(std::vector<std::vector<char>>& matrix) 
	{
		if (matrix.size() == 0)
			return 0;
		
		int rows = matrix.size();
		int columns = matrix[0].size();

		/*Create a similar mxn vector but each element in the 2-D vector will be a pair of 2 elements*/
		std::vector<std::vector<std::pair<int, int>>> dpVect(rows, std::vector<std::pair<int, int>>(columns));

		int max = 0;

		/*Iterate for the entire dpVect matrix*/
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (matrix[i][j] == '0')
				{
					dpVect[i][j] = std::make_pair(0,0);
				}
				else
				{
					int x = 0, y = 0;
					/*If matrix element above is 1*/
					if (((i - 1) >= 0) && (matrix[i - 1][j] == '1'))
					{
						/*We store the value of the first value of the above element meaning that the column matches */
						x = dpVect[i - 1][j].first + 1;
					}

					if (((j - 1) >= 0) && (matrix[i][j - 1] == '1'))
					{
						/*We store the value of the second value of the left element meaning that the column matches */
						y = dpVect[i][j-1].second + 1;
					}

					dpVect[i][j] = std::make_pair(x,y);

					int min = INT_MAX;

					/*Iterating through all the rows above it which is part of a continuous series of 1's*/
					for (int k = 0; k <= x; k++)
					{
						/*We find the min value continuous columns of 1 for every row in the dpVect matrix*/
						if (dpVect[i - k][j].second < min)
							min = dpVect[i - k][j].second;

						/*Select the max value of the rectangle area*/
						if (max < (k + 1)*(min + 1))
							max = (k + 1)*(min + 1);
					}
				}
			}
		}
		return max;
	}
};

int main()
{

}