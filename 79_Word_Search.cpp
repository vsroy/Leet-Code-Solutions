/*Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
those horizontally or vertically neighboring. The same letter cell may not be used more than once.*/

#include<iostream>
#include<vector>
#include<string>

class Solution
{
public:

	bool PatternPresent(int i, int j,int pos, std::vector<std::vector<char>>& board,std::string& word)
	{

		/*First element has already matched*/

		/*If row and column value are off limits or current position in grid does not match value in letter*/
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[pos] != board[i][j])
			return false;

		/*We have reached the end of the array*/
		if (pos == word.size() - 1)
			return true;

		char cur = board[i][j];	/*Store the current value of board in temporary variable to mark as visited*/
		board[i][j] = 0;
		bool found = PatternPresent(i - 1, j, pos + 1, board, word) ||	/*Using backtracking to validate the area around the cell*/
					 PatternPresent(i + 1, j, pos + 1, board, word) ||
					 PatternPresent(i, j - 1, pos + 1, board, word) ||
					 PatternPresent(i, j+1, pos + 1, board, word);
		board[i][j] = cur;	/*Remove the visited mark for the next character*/
		return found;
	}

	bool exist(std::vector<std::vector<char>>& board, std::string word)
	{
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if ((PatternPresent(i, j, 0, board, word) == true))
					return true;
		return false;
	}
};


int main()
{
	Solution s1;
	std::vector<std::vector<char>> ipVect{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	std::cout << s1.exist(ipVect,"ABCB");
	return 0;
}