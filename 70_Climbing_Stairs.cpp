#include<iostream>

int FindSteps(int n)
{
	if (n <= 1)
		return n;
	return (FindSteps(n - 1) + FindSteps(n - 2));
}

int climbStairs(int n) 
{
	return FindSteps(n + 1); /*Will call the function to find the Fibonacci of n+1*/
}

int main()
{
	std::cout << climbStairs(4);
	return 0;
}