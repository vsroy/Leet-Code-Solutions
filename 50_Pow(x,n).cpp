/*Implement pow(x, n), which calculates x raised to the power n (xn).*/
#include<iostream>

class Solution 
{
public:
	double myPow(double x, int n) 
	{
		//Alternative solution
		/*
		if (n == 0)
			return 1;
		bool positive = true;
		if (n < 0)
		{
			positive = false;
			n = std::abs(n);
		}
			
		double result = x;
		n--;
		while (n > 0)
		{
			result = result * x;
			n--;
		}

		if (!positive)
			return (1 / result);
		else
			return result;
		*/

		if (n == 0)
			return 1.0;
		if (n < 0)
			x = 1.0 / x;
		
		double product;
		if (n % 2 == 0)
			product = 1.0;
		else
			product = x;

		n = n / 2;

		while (n != 0)
		{
			x = x * x;
			if (n % 2 != 0)
				product = product*x;
			n = n / 2;
		}
		return product;
	}
};

int main()
{
	Solution s1;
	std::cout.precision(5);
	printf("%.5f",s1.myPow(2,4));
	return 0;
}