#include<iostream>
#include<string>

int lengthOfLastWord(std::string s) 
{
	int latestLength = 0;
	int lastLength = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] != ' ') && (i < s.length() - 1))	//We have nor encountered a space and we are not in the last char of the string
		{
			latestLength++;
		}
		else
		{
			if ((i == (s.length() - 1)) && (s[i] != ' '))
				latestLength++;
			if (latestLength > 0)
				lastLength = latestLength;
			latestLength = 0;
		}
	}

	return lastLength;
}

int main()
{
	//std::cout << lengthOfLastWord("a ");
	std::cout << lengthOfLastWord("b   a    ");
	return 0;
}

//OLD LOGIC
/*
for (int i = 0; i < s.length(); i++)
{
if (s[i] != ' ')
latestLength++;
if (i == (s.length() - 1))	//the iteration is complete
return latestLength;
if (s[i] == ' ')
{
lastLength = latestLength;
latestLength = 0;
}
}
*/