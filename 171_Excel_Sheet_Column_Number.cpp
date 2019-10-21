/*Given a column title as appear in an Excel sheet, return its corresponding column number.*/
#include<iostream>
#include<string>

int titleToNumber(std::string s) 
{
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		char temp = s[i];
		result = result * 26;
		result = result + temp - 'A';
		result += 1;
	}
	return result;
}

int main()
{
	std::cout << titleToNumber("AB");
	return 0;
}