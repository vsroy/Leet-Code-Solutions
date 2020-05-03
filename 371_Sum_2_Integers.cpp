/*Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.*/

#include<iostream>

class Solution 
{
public:
	int getSum(int a, int b) 
	{
		unsigned int an = (unsigned)a;
		unsigned int bn = (unsigned)b;

		int temp;
		while (bn != 0)
		{
			temp = bn;
			bn = an & bn;
			an = an ^ temp;
			bn = bn << 1;
		}
		return an;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.getSum(2,1);
	return 0;
}