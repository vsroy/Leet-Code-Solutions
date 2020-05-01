#include<iostream>

class Solution 
{
public:
	bool isPowerOfThree(int n) 
	{
		if (n < 1)
			return false;
		while (n % 4 == 0)
			n /= 4;
		if (n == 1 || n == 4)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s1;
	/*
	std::cout << s1.isPowerOfThree(27) << std::endl;
	std::cout << s1.isPowerOfThree(0) << std::endl;
	std::cout << s1.isPowerOfThree(9) << std::endl;
	std::cout << s1.isPowerOfThree(45) << std::endl;
	*/

	std::cout << s1.isPowerOfThree(5) << std::endl;
	return 0;
}