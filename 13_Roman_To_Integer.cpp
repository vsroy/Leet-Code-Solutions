/*Write a program to convert Roman numeral to integer*/
/*https://leetcode.com/problems/roman-to-integer/*/

#include<iostream>
#include<string>
int romanToInt(std::string s)
{
	int counter = 0;
	int totalSum = 0;
	while (counter < s.length())
	{
		int romanChar = s[counter];
		if (s[counter] == 'I')
		{
			if (counter + 1 < s.length() && s[counter + 1] == 'V')
			{
				totalSum += 4;
				counter += 2;
			}
			else if (counter + 1 < s.length() && s[counter + 1] == 'X')
			{
				totalSum += 9;
				counter += 2;
			}
			else
			{
				totalSum += 1;
				counter++;
			}
		}
		else if (s[counter] == 'X')
		{
			if (counter + 1 < s.length() && s[counter + 1] == 'L')
			{
				totalSum += 40;
				counter += 2;
			}
			else if (counter + 1 < s.length() && s[counter + 1] == 'C')
			{
				totalSum += 90;
				counter += 2;
			}
			else
			{
				totalSum += 10;
				counter++;
			}
		}
		else if (s[counter] == 'C')
		{
			if (counter + 1 < s.length() && s[counter + 1] == 'D')
			{
				totalSum += 400;
				counter += 2;
			}
			else if (counter + 1 < s.length() && s[counter + 1] == 'M')
			{
				totalSum += 900;
				counter += 2;
			}
			else
			{
				totalSum += 100;
				counter++;
			}
		}
		else if (s[counter] == 'V')
		{
			totalSum += 5;
			counter++;
		}

		else if(s[counter] == 'L')
		{
			totalSum += 50;
			counter++;
		}

		else if (s[counter] == 'D')
		{
			totalSum += 500;
			counter++;
		}

		else if (s[counter] == 'M')
		{
			totalSum += 1000;
			counter++;
		}
	}
	return totalSum;
}

int main()
{
	std::string romanInput;
	std::cin >> romanInput;
	std::cout << romanToInt(romanInput);
	return 0;
}