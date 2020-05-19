/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,*/

#include<iostream>

class Solution 
{
public:
	int fib(int N) 
	{
		/*
		if (N <= 1)
			return N;
		return fib(N - 1) + fib(N - 2);
		*/

		int first = 0;
		int second = 1;

		int i = 2;
		int sum = 0;
		while (i <= N)
		{
			sum = first + second;
			first = second;
			second = sum;
			i++;
		}
		return sum;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.fib(4);
	return 0;
}