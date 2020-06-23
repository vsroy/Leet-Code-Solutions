/*Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int numSquares(int n) 
	{
		std::vector<int> vect1(n+1);
		vect1[0] = 0;
		vect1[1] = 1;
		vect1[2] = 2;
		vect1[3] = 3;

		/*Loop from 4 to n*/
		for (int i = 4; i <= n; i++)
		{
			/*Max value of all squares at this point will be i because 1*1 + 1*1 ... */
			vect1[i] = i;

			/*Now run a loop from 1 to sqrt(n)*/
			for (int x = 1; x <= ceil(std::sqrt(n)); x++)
			{
				/*For every val, calculate its square*/
				int temp = x * x;
				if (temp > i)
					break;
				else
				{
					/*Check whether square of that val is  1 + (square root number till i - temp)*/
					vect1[i] = std::min(vect1[i], 1 + vect1[i - temp]);
				}
			}
		}
		return vect1[n];
	}
};

int main()
{
	Solution s1;
	std::cout << s1.numSquares(1);
	return 0;
}