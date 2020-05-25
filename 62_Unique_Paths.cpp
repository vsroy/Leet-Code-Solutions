/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner 
of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	int uniquePaths(int m, int n) 
	{
		
		/*We can solve this problem using simple recursion*/

		/*Firstly, for every cell in the first row and first columns, number of unique paths will always be 1*/

		//if (m == 1 || n == 1)
			//return 1;

		//return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);	/*For every cell not in first row and first column, unique path will be */
																/*sum of the value of cell to the letf and above it*/

		std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));	/*Creating an m x n vector and initializing all values to 0*/
		for (int i = 0; i<m; i++){
			dp[i][0] = 1;                                       // Fill first row with 1
		}
		for (int i = 0; i<n; i++){
			dp[0][i] = 1;                                       // Fill first column with 1
		}
		for (int i = 1; i <m; i++){
			for (int j = 1; j <n; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m-1][n-1];
	}															

};

int main()
{
	Solution s1;
	std::cout << s1.uniquePaths(7,3);
	return 0;
}