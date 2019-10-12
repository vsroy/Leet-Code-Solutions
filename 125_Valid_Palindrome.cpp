/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.*/
#include<iostream>
#include<string>
#include<ctype.h>

bool isPalindrome(std::string s) 
{
	if (s.empty())
		return true;
	int start = 0;
	int end = s.length() - 1;
	while ((start < s.length()) && (end >= 0))
	{
		char startChar = s[start];
		char endChar = s[end];
		if (s[start] == ' ' || s[end] == ' ')
		{
			if (s[start] == ' ')
				start++;
			if (s[end] == ' ')
				end--;
			continue;
		}

		if (!isalnum(s[start]) || !isalnum(s[end]))
		{
			if (!isalnum(s[start]))
				start++;
			if (!isalnum(s[end]))
				end--;
			continue;
		}
		if (tolower(s[start]) != tolower(s[end]))
			return false;
		start++;
		end--;
	}
	return true;
}

int main()
{
	//std::string ipString = "A man, a plan, a canal : Panama";
	std::string ipString = "AA";
	std::cout << "Is the following string a Palindrome ?\n" << ipString << std::endl;
	isPalindrome(ipString) ? std::cout << "True" : std:: cout << "False";
	return 0;
}