/*Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.*/

#include<iostream>

class Solution 
{
public:
	int findComplement(int num) 
	{
		int sum = 0, i = 0;
		while (num)
		{
			if (!(num & 1)) /*If the bit is zero, we invert that and calculate sum*/
			{
				sum += pow(2, i);
			}
			i++;	/*For bits 1, we need not calcluate sum*/
			num = num >> 1;	/*Right shift bit by 1*/
		}

		return sum;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.findComplement(5);
	return 0;
}