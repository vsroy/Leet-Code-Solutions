/*Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstring>

class Solution 
{
public:
	std::vector<std::string> findWords(std::vector<std::string>& words) 
	{
		std::string row1 = "qwertyuiop";
		std::string row2 = "asdfghjkl";
		std::string row3 = "zxcvbnm";

		std::vector<std::string> resultVect;

		for (int i = 0; i < words.size(); i++)
		{
			std::string currentWord = words[i];
			
			char firstLetter = tolower(currentWord[0]);
			std::string presentRow = "";

			if (row1.find(firstLetter) != std::string::npos)
				presentRow = row1;
			else if (row2.find(firstLetter) != std::string::npos)
				presentRow = row2;
			else
				presentRow = row3;
			
			bool isInRow = true;
			for (int j = 0; j < currentWord.length(); j++)
			{
				char currChar = tolower(currentWord[j]);
				if (presentRow.find(currChar) == std::string::npos)
				{
					isInRow = false;
					break;
				}
			}
			if (isInRow)
				resultVect.push_back(currentWord);
		}
		return resultVect;
	}
};

int main()
{
	std::vector<std::string> vect1{"Hello", "Alaska", "Dad", "Peace" };
	Solution s1;
	std::vector<std::string> resultVect = s1.findWords(vect1);
	for (int i = 0; i < resultVect.size(); i++)
		std::cout << resultVect[i] << " ";
	return 0;
}