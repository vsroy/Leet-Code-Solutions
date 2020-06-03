/*Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

class Solution 
{
public:

	/*Utility program to find the min of 3 values*/

	int min3Val(int x, int y, int z)
	{
		return std::min(x, std::min(y, z));
	}
	
	int minDistance(std::string word1, std::string word2) 
	{
		int m = word1.length();
		int n = word2.length();

		std::vector<std::vector<int>> dp;

		for (int i = 0; i <= m; i++)
		{
			std::vector<int> sampleVect(n+1);
			dp.push_back(sampleVect);
		}

		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				// If first string is empty, only option is to 
				// insert all characters of second string 
				if (i == 0)
					dp[i][j] = j;
				
				// If second string is empty, only option is to 
				// remove all characters of second string 
				else if (j == 0)
					dp[i][j] = i;

				else if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min3Val(dp[i - 1][j],
					dp[i][j - 1],
					dp[i - 1][j - 1]);
			}
		}
		return dp[m][n];
	}
};

int main()
{
	Solution s1;
	std::cout << s1.minDistance("intention","execution");
	return 0;
}