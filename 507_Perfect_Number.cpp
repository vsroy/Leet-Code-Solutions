/*We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.*/

#include<iostream>

class Solution 
{
public:
	bool checkPerfectNumber(int num) 
	{
		int totalSum = 0;
		for (int i = 2; i*i < num; i++)
		{
			if (num % i == 0)
			{
				if (i*i == num)	/*In this case we include only a single number*/
					totalSum += i;
				else
					totalSum += i + num / i;	/*In this case, we include the divisor and quotient*/
			}
		}
		totalSum += 1;
		if (totalSum == num)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.checkPerfectNumber(1);
	return 0;
}