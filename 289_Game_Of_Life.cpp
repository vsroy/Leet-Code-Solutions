/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a 
cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, 
vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. 
The next state is created by applying the above rules simultaneously to every cell 
in the current state, where births and deaths occur simultaneously.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	void gameOfLife(vector<vector<int>>& board) 
	{
		/*Solving it in place. We code the transition so that we can check which value it was */
		/*
		0 -> dead
		1 -> live
		2 -> dead->live
		3 -> live->dead
		*/

		int rows = board.size();
		int columns = board[0].size();

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				int liveCount = 0;
				for (int k = -1; k <= 1; k++)
				{
					for (int l = -1; l <= 1;l++)
					{
						if (i + k >= 0 && i + k < rows && j + l >= 0 && j + l < columns && !(k == 0 && l == 0))
							if (board[i + k][j + l] == 1 || board[i + k][j + l] == 3)
								liveCount++;
					}
				}
				if (board[i][j] == 1)
				{
					if (liveCount < 2 || liveCount > 3)
						board[i][j] = 3;
				}
				else
				{
					if (liveCount == 3)
						board[i][j] = 2;
				}
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (board[i][j] == 2)
					board[i][j] = 1;
				else if (board[i][j] == 3)
					board[i][j] = 0;
			}
		}
	}
};

int main()
{
	Solution s1;
	vector<vector<int>> ipVect = {
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};

	s1.gameOfLife(ipVect);

	for (auto i : ipVect)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}