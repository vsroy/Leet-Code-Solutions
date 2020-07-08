#include<iostream>
#include<vector>
using namespace std;


class Solution 
{
public:
	/*This utility function will make '-' lying on edges and connected to it '0' */
	void FloodFillUtility(vector<vector<char>>& board,int x, int y, char prevChar, char newChar)
	{
		int rows = board.size();
		int columns = board[0].size();
		
		if (x < 0 || x >= rows || y < 0 || y >= columns)
			return;

		/*Checking whether value is '-'*/
		if (board[x][y] != prevChar)
			return;
			
		/*Replace '-' with 'O'*/
		board[x][y] = newChar;
		
		/*Recur for adjacent cells*/
		FloodFillUtility(board, x + 1, y,prevChar,newChar);
		FloodFillUtility(board, x - 1,y,prevChar,newChar);
		FloodFillUtility(board, x, y + 1,prevChar,newChar);
		FloodFillUtility(board, x, y - 1,prevChar,newChar);
	}

	void solve(vector<vector<char>>& board) 
	{
		if (board.size() == 0)
			return;
		/*Replace all zeroes with '-'*/
		int rows = board.size();
		int columns = board[0].size();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				if (board[i][j] == 'O')
					board[i][j] = '-';
		}

		/*Call Floodfill algorithm for all edge elements*/
		
		/*Leftmost column*/
		for (int i = 0; i < rows; i++)
		{
			if (board[i][0] == '-')
				FloodFillUtility(board,i,0,'-','O');
		}

		/*Rightmost column*/
		for (int i = 0; i < rows; i++)
		{
			if (board[i][columns-1] == '-')
				FloodFillUtility(board, i, columns-1, '-', 'O');
		}

		/*Top row*/
		for (int i = 0; i < columns; i++)
		{
			if (board[0][i] == '-')
				FloodFillUtility(board, 0, i, '-', 'O');
		}

		/*Bottom row*/
		for (int i = 0; i < columns; i++)
		{
			if (board[rows-1][i] == '-')
				FloodFillUtility(board, rows-1, i, '-', 'O');
		}

		/*Finally, replace all remaining '-' with 'X'*/

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				if (board[i][j] == '-')
					board[i][j] = 'X';
	}
};

int main()
{
	Solution s1;

	vector<vector<char>>ipVect{ { 'X', 'X', 'X', 'X' },
	{ 'X', 'O', 'O', 'X' },
	{ 'X', 'X', 'O', 'X' },
	{ 'X', 'O', 'X', 'X' },
	};

	s1.solve(ipVect);

	for (auto i : ipVect)
	{
		for (auto j : i)
			std::cout << j << " ";
		cout << endl;
	}
	
	return 0;
}