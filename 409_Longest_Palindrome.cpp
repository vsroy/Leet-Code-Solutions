/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.*/

#include<iostream>
#include<map>
#include<string>

class Solution 
{
public:
	int longestPalindrome(std::string s) 
	{
		std::map<char, int> palindromeChar;
		
		for (int i = 0; i < s.length(); i++)
			palindromeChar[s[i]] += 1;

		std::map<char, int>::iterator it;
		
		int totalOccur = 0; int roundedOccur = 0;
		for (it = palindromeChar.begin(); it != palindromeChar.end(); it++)
		{
			totalOccur += it->second;
			roundedOccur += (it->second / 2) * 2;	/*If character has an odd count, do not consider one occurrence of the character*/
		}
		if (totalOccur == roundedOccur)
			return totalOccur;			/*All characters have even count*/
		else
			return roundedOccur + 1;	/*We can allow only one occurrence of a character with odd count*/
	}
};

int main()
{
	Solution s1;
	std::cout << s1.longestPalindrome("abccccdd");
	return 0;
}
