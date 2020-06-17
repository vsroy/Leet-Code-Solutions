/*Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	bool isValidSudoku(std::vector<std::vector<char>>& board) 
	{
		int k;
		
		vector<vector<int>> row(9,vector<int>(9,0));	//i has appeared in row i
		vector<vector<int>> column(9, vector<int>(9, 0)); // i has appeared in column j 
		vector<vector<int>> box(9, vector<int>(9, 0)); // i has appeared in row k

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0';
					num--;

					k = i / 3 * 3 + j / 3;
					if (row[num][i] || column[num][j] || box[num][k])
						return false;
					row[num][i] = column[num][j] = box[num][k] = 1;
				}
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}