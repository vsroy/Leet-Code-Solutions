/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.*/
#include<iostream>
#include<string>

std::string convertToTitle(int n) 
{
	std::string resultString;
	while (n > 0)
	{
		int rem = n % 26;
		if (rem == 0)
		{
			resultString += 'Z';
			n = (n / 26) - 1;
		}
		else
		{
			resultString += (rem - 1) + 'A';
			n = n / 26;
		}
	}
	reverse(resultString.begin(), resultString.end());
	return resultString;
}

int main()
{
	std::cout << convertToTitle(701);
	return 0;
}