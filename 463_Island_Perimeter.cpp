/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is 
exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size(), res = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				if (grid[i][j] == 1)
				{
					if (i == 0 || grid[i - 1][j] == 0) res++;
					if (i == n - 1 || grid[i + 1][j] == 0) res++;
					if (j == 0 || grid[i][j - 1] == 0) res++;
					if (j == m - 1 || grid[i][j + 1] == 0) res++;
				}
		return res;
	}
};

int main()
{
	std::vector<std::vector<int>> grid{ { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 } };
	Solution s1;
	int a = s1.islandPerimeter(grid);
	return 0;
}