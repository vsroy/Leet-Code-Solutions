#include<iostream>

class Solution 
{
public:
	bool isPerfectSquare(int num) 
	{
		for (int i = 1; i*i <= num; i++)
		{
			if (i*i == num)
				return true;
			/*
			if ((num % i == 0) && (num / i == i))
				return true;
				*/
		}
		return false;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.isPerfectSquare(14);
	return 0;
}