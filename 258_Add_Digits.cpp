/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.*/
#include<iostream>

int addDigits(int num) 
{
	while ((num / 10) != 0)
	{
		int tempVal = num;
		int total = 0;
		while ((tempVal / 10) != 0)
		{
			total = total + (tempVal % 10);
			tempVal = tempVal / 10;
		}
		total += tempVal;
		num = total;
	}
	return num;
}

int main()
{
	std::cout << addDigits(38);
	return 0;
}