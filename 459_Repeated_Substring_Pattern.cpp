/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000*/
/*Solution to this question can be found in the link - 
https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/*/

#include<iostream>
#include<string>

class Solution 
{
public:
	bool repeatedSubstringPattern(std::string s) 
	{
		/*We solve this using a mehodology where prefix = suffix and prefix is the longest in the string*/
		
		int suffixCounter = 1;
		int lastSuffixCounter = 1;
		int prefixLength = 0;
		while (suffixCounter < s.length())
		{
			if (s[suffixCounter] == s[prefixLength])	//ABCABCABCABCABC
			{
				prefixLength++;
				suffixCounter++;
			}
			else
			{
				prefixLength = 0;
				suffixCounter = lastSuffixCounter + 1;
				lastSuffixCounter++;
			}
		}
		int div = s.length() - prefixLength;	/*We get the length of the longest prefix = suffix. We subtract the len of longest_prefix from string length*/

		if (prefixLength > 0)
		{
			if (s.length() % div == 0)			/*If string length modulo previous value == 0, then return true.*/
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.repeatedSubstringPattern("ABAC");
	return 0;
}