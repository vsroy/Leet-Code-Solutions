/*Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.*/

#include<iostream>
#include<string>

class Solution 
{
public:
	bool detectCapitalUse(std::string word) 
	{
		int capitalLetters = 0;
		int smallLetters = 0;
		for (int i = 1; i < word.length(); i++)
		{
			int asciiInt = int(word[i]);
			if (asciiInt >= 65 && asciiInt <= 90)
				capitalLetters++;
			else if (asciiInt >= 97 && asciiInt <= 122)
				smallLetters++;
			else
				return false;	/*charracter is not an alphabet*/
		}

		if (capitalLetters > 0 && smallLetters > 0)	/*If letters are small and capital*/
			return false;
		else if (capitalLetters > 0 && smallLetters == 0)	/*If letters are only capital*/
		{
			if (int(word[0]) >= 65 && int(word[0]) <= 90)	/*If first letter is capital*/
				return true;
			else
				return false;								/*If first letter is small*/
		}
		else if (smallLetters > 0 && capitalLetters == 0)
			return true;
		else/*Case when input length is 1*/
		{
			int asciiInt = int(word[0]);
			if ((asciiInt >= 65 && asciiInt <= 90) || (asciiInt >= 97 && asciiInt <= 122))
				return true;
		}
		return false;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.detectCapitalUse("Google");
	return 0;
}