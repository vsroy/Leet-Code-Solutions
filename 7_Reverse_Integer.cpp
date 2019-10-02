/*Given a 32-bit signed longeger, reverse digits of an longeger.*/
#include<iostream>

long reverse(int x)
{
	long long int y = 0;
	while (x != 0)
	{
		int r = x % 10;
		y = 10 * y + r;
		x = x / 10;
	}
	if (y >= INT_MAX || y <= INT_MIN)
		return 0;
	else
		return y;
}

long main()
{
	long input;
	std::cin >> input;
	std::cout << reverse(input);
	return 0;
}