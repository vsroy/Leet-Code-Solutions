/*Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.*/
#include<iostream>
#include<string>

std::string countAndSay(int n) 
{
	int startVal = 1;
	std::string startString = "1";
	for (int i = 1; i < n; i++)
	{
		int stringIndex = 1;
		int currCharCount = 1;
		char currChar = startString[0];
		std::string resultChar = "";
		while (stringIndex < startString.size())
		{
			if (startString[stringIndex] == currChar)
			{
				currCharCount++;
				stringIndex++;
			}
			else
			{
				resultChar = resultChar + std::to_string(currCharCount) + currChar;
				currChar = startString[stringIndex];
				stringIndex++;
				currCharCount = 1;
			}
		}
		if (currCharCount > 0)
			resultChar = resultChar + std::to_string(currCharCount) + currChar;
		startString = resultChar;
	}
	return startString;
}

int main()
{
	std::cout << countAndSay(8);
	return 0;
}