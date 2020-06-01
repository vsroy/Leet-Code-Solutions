/*Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.*/
/*Detailed explanation is given in this video link - https://www.youtube.com/watch?v=EIf9zFqufbU*/

#include<iostream>
#include<string>
#include<vector>

class Solution 
{
public:
	int countSubstrings(std::string s) 
	{
		int count = 0;
		std::vector<std::vector<int>> matrixVect;

		/*Initializing the M x M array*/
		for (int i = 0; i < s.length(); i++)
		{
			std::vector<int> ipVect(s.length());
			matrixVect.push_back(ipVect);
		}

		/*
		for (auto i : matrixVect)
		{
			for (auto j : i)
				std::cout << j << " ";
			std::cout << std::endl;
		}
		*/

		/*Every diagonal element will be a palindrome, so count will increase by 1*/
		for (int i = 0; i < s.length(); i++)
		{
			matrixVect[i][i] = 1;
			count++;
		}

		/*Now, going by every column*/
		for (int col = 1; col < s.length(); col++)
		{
			for (int row = 0; row < col; row++)
			{
				/*If length of the current string is 2, we need to compare only the 2 characters*/
				if ((row == col - 1) && (s[row] == s[col]))
				{
					matrixVect[row][col] = 1;
					count++;
				}
				else if ((matrixVect[row + 1][col - 1] == 1) && (s[row] == s[col]))
				{
					/*If the cell that is to the bottom left of the cell is 1 and first and last char are equal, then it is a palindrome*/
					matrixVect[row][col] = 1;
					count++;
				}
			}
		}
		return count;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.countSubstrings("aaa");
	return 0;
}