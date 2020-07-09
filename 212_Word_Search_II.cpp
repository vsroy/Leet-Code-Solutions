//Given a 2D board and a list of words from the dictionary, find all words in the board.
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
//horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution 
{
	//Alternate solution
	/*
	vector<string>resultVect;

	//Function to check if word is present in the dictionary
	bool IsWordPresentInDict(vector<string> words,string word)
	{
		if (find(words.begin(), words.end(), word) != words.end())
			return true;
		else
			return false;
	}

	void findWordsUtil(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string> words,int i, int j, string str)
	{
		int rows = board.size();
		int columns = board[0].size();
		//Mark the current cell as visited
		visited[i][j] = true;

		str += board[i][j];

		//If the word is present in the dictionary
		if (IsWordPresentInDict(words, str))
			resultVect.push_back(str);

		//Traverse all the cells of the board matrix
		for (int row = i - 1; row <= i + 1 && row < rows; row++)
			for (int col = j - 1; j <= j + 1 && col < columns; col++)
				if (row >= 0 && col >= 0 && !visited[row][col])
					findWordsUtil(board,visited,words,row,col,str);

		//Erase current character of the string and mark visited as false
		str.erase(str.length()-1);
		visited[i][j] = false;
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{
		int rows = board.size();
		int columns = board[0].size();

		//Create a m x n visited vector
		vector<vector<bool>> visitedVect(rows, vector<bool>(columns,false));

		//Initialize current string
		string str = "";

		//Initialize current character and look for all words starting with this character
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				findWordsUtil(board, visitedVect, words, i, j, str);

		return resultVect;
	}
	*/
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		if (board.empty() || words.empty())
			return ans;
		unordered_set<string> pre, wordset(words.begin(), words.end());
		int cnt = 1;
		while (cnt > 0) {
			for (int i = 1; cnt > 0; ++i) {
				cnt = 0;
				for (auto& str : words) {
					if (i < str.size()) {
						cnt++;
						pre.insert(str.substr(0, i));
					}
				}
			}
		}
		int m = board.size(), n = board[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				string word = "";
				dfs(board, pre, wordset, ans, word, i, j);
			}
		}
		return ans;
	}

	void dfs(vector<vector<char>>& board, unordered_set<string>& pre, unordered_set<string>& fin, vector<string>& ans, string& word, int i, int j) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '0')
			return;
		word += board[i][j];
		if (fin.find(word) != fin.end()) {
			ans.emplace_back(word);
			fin.erase(word);
		}
		if (pre.find(word) == pre.end()) {
			word.pop_back();
			return;
		}
		char t = board[i][j];
		board[i][j] = '0';
		dfs(board, pre, fin, ans, word, i + 1, j);
		dfs(board, pre, fin, ans, word, i, j + 1);
		dfs(board, pre, fin, ans, word, i - 1, j);
		dfs(board, pre, fin, ans, word, i, j - 1);
		word.pop_back();
		board[i][j] = t;
	}

};

int main()
{
	Solution s1;
	vector<vector<char>> board{
		{ 'o', 'a', 'a', 'n' },
		{ 'e', 't', 'a', 'e' },
		{ 'i', 'h', 'k', 'r' },
		{ 'i', 'f', 'l', 'v' }
	};
	vector<string> words{ "oath", "pea", "eat", "rain" };

	vector<string> resultVect = s1.findWords(board,words);

	for (auto i : resultVect)
		cout << i << " ";

	return 0;
}