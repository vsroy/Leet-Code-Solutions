/*Determine whether an integer is a palindrome.An integer is a palindrome when it reads the same backward as forward.*/
#include<iostream>
#include<string>
#include<sstream>
bool isPalindrome(int x) 
{
	std::stringstream ss;
	ss << x;
	std::string opString = ss.str();
	int length = opString.length();
	int end = opString.length() - 1;
	int start = 0;
	while (start < opString.length() && end >= 0)
	{
		if (opString[start] != opString[end])
			return false;
		start++; 
		end--;
	}
	return true;
}

int main()
{
	int input;
	std::cin >> input;
	if (isPalindrome(input))
		std::cout << "True";
	else
		std::cout << "False";
	return 0;
}