/*Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.*/
#include<iostream>

bool isUgly(long num) 
{
	if (num < 0 || num == 0)
		return false;
	//Print all the prime factors of the input number
	while (num%2 == 0)
		num = num / 2;	/*Reducing the number down to an odd number*/

	for (int i = 3; i <= sqrt(num); i+=2)
	{
		while (num%i == 0)
		{
			if ((i != 3) && (i != 5))
				return false;
			num = num / i;
		}
	}
	
	/*Condition that hendles if there is a prime number greater than 2*/
	if (num > 2)
	{
		if ((num != 3) && (num != 5))
			return false;
	}
	return true;
}

int main()
{
	std::cout << isUgly(9);
	return 0;
}