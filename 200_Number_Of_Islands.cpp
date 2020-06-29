/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water 
and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.*/

#include<iostream>
#include<vector>

class Solution 
{
public:

	int islandHelper(std::vector<std::vector<char>>& grid, int i, int j)
	{
		if (i < 0 || i > grid.size() - 1  || j < 0 || j > grid[0].size() - 1)
			return 0;
		if (grid[i][j] == '0' || grid[i][j] == '*')
			return 0;

		/*Mark those cells that have been visited and which are 1's*/
		grid[i][j] = '*';
		islandHelper(grid,i - 1,j);
		islandHelper(grid, i + 1, j);
		islandHelper(grid, i, j+1);
		islandHelper(grid, i, j-1);

		return 1;
	}

	int numIslands(std::vector<std::vector<char>>& grid) 
	{
		int count = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size();j++)
			{
				if (grid[i][j] == '1')
					count += islandHelper(grid,i,j);
			}
		}
		return count;
	}
};

int main()
{
	Solution s1;

	std::vector<std::vector<char>> grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};

	std::cout << s1.numIslands(grid);

	return 0;	
}