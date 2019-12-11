/*Given an integer, write a function to determine if it is a power of two.*/
#include<iostream>

bool isPowerOfTwo(int n) 
{
	if (n < 0)
		return false;
	if (n == 0)
		return false;
	if (n == 2)
		return true;
	int remainder = 0;
	while (n > 2)
	{
		remainder = n % 2;
		if (remainder == 1)
			return false;
		n = n / 2;
	}
	return true;
}

int main()
{
	std::cout << isPowerOfTwo(3);
	return 0;
}