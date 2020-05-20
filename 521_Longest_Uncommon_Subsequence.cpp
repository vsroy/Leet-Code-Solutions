/*Given two strings, you need to find the longest uncommon subsequence of this two strings. The longest uncommon subsequence 
is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other string.
A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. 
Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. 
If the longest uncommon subsequence doesn't exist, return -1.*/

#include<iostream>
#include<string>

class Solution 
{
public:
	int findLUSlength(std::string a, std::string b) 
	{
		if (a == b)
			return 0;
		
		if (a.length() == b.length())
			return a.length();

		if (a.length() > b.length())
			return a.length();
		else
			return b.length();
	}
};

int main()
{
	Solution s1;
	std::cout << s1.findLUSlength("aba","cdc");
	return 0;
}