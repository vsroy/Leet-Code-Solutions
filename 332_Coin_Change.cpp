/*You are given coins of different denominations and a total amount of money amount. Write a function to compute 
the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any 
combination of the coins, return -1.
For Hint - https://www.geeksforgeeks.org/coin-change-dp-7/
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	
	int coinChange(vector<int>& coins, int amount) {
		vector<long> x(amount + 1, 0);

		for (int i = 1; i <= amount; i++) {
			long min = INT_MAX;

			for (auto j : coins){
				if (i - j >= 0) {
					long  curr = x[i - j] + 1;

					if (curr < min) {
						min = curr;
					}

				}
			}

			x[i] = min < 0 ? -1 : min;
		}
		for (auto i : x){
			cout << i << " ";
		}

		return x[amount] == INT_MAX ? -1 : x[amount];
	}

	/* Alternate solution
	int coinHelper(std::vector<int>& coins, int amount, int size)
	{
		//The sum has been reached then there is one solution
		if (amount == 0)
			return 1;

		//If amount is less than 0, then no solution exists if we go by that path
		if (amount < 0)
			return 0;

		//If amount remaining > 0 and if there are no coins remaining, then no solution exists
		if (amount >= 1 && size <= 0)
			return 0;

		return coinHelper(coins, amount, size - 1) + coinHelper(coins, amount - coins[size-1], size);
	}

	int coinChange(std::vector<int>& coins, int amount) 
	{
		int result = coinHelper(coins,amount,coins.size());
		return (result > 0) ? result : -1;
	}
	*/
	
};

int main()
{
	Solution s1;
	std::vector<int> ipVect{1,2,5};
	std::cout << s1.coinChange(ipVect,11);
	return 0;
}