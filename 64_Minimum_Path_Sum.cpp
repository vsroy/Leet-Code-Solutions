/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the 
sum of all numbers along its path.
Note: You can only move either down or right at any point in time.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int minPathSum(std::vector<std::vector<int>>& grid) 
	{
		/*Solving this using Dynamic Programming*/
		int rows = grid.size();
		int columns = grid[0].size();

		/*For the first column, we will fill values above it*/
		for (int i = 1; i < rows; i++)
			grid[i][0] += grid[i - 1][0];

		/*For filling up the first row, we will fill values to the left of it*/
		for (int j = 1; j < columns; j++)
			grid[0][j] += grid[0][j - 1];

		/*Now, for filling up the remaining cells, we will be filling up the min of the cell above/below it*/
		for (int i = 1; i < rows; i++)
			for (int j = 1; j < columns; j++)
				grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);

		/*We will be returning the value of the bottom right cell in the grid which will give us the minimum path sum*/
		return grid[rows - 1][columns - 1];
	}
};

int main()
{
	std::vector<std::vector<int>> ipVect{ {1,3,1},{1,5,1},{4,2,1} };
	Solution s1;
	std::cout << s1.minPathSum(ipVect);
	return 0;
}