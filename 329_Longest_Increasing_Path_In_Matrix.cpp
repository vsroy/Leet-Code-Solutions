/*Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
To solve this, we using the Dynamic Programming approach where where we maintain a 2D matrix dp[][] where 
dp[i][j] will store the longest possible subsequence of the cell starting from ith row and jth column
To find dp[i][j] , we use the formula dp[i][j] = max(dp[i][j+1],dp[i+1][j])
*/

class Solution 
{
public:

	bool isValid(int x0, int y0, int m, int n){
		return (x0 >= 0 && x0<m && y0 >= 0 && y0<n);
	}

	int helper(vector<vector<int>> & mat, vector<vector<int>> & dp, int dx[], int dy[], int x0, int y0, int m, int n){
		if (dp[x0][y0] != 0)
			return dp[x0][y0];
		int ans = 1;
		for (int i = 0; i<4; i++){
			int x1 = x0 + dx[i];
			int y1 = y0 + dy[i];
			if (isValid(x1, y1, m, n) && mat[x1][y1] < mat[x0][y0]){
				ans = max(ans, 1 + helper(mat, dp, dx, dy, x1, y1, m, n));
			}
		}
		dp[x0][y0] = ans;
		return ans;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		if (n == 0)
			return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };
		int ans = 0;
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++)
				ans = max(ans, helper(matrix, dp, dx, dy, i, j, m, n));
		}
		return ans;
	}
};

int main()
{

}