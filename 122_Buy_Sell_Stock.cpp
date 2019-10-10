#include<iostream>
#include<vector>

int maxProfit(std::vector<int>& prices) 
{
	int maxprofit = 0;
	if (prices.size() < 2)
	{
		return 0;
	}
	for (int i = 1; i < prices.size(); i++)
	{
		int temp = prices[i] - prices[i - 1];
		if (temp > 0)
		{
			maxprofit += temp;
		}
	}
	return maxprofit;
}

int main()
{
	//std::vector<int> ipVect{7,1,5,3,6,4};
	std::vector<int> ipVect{ 1,2,3,4};
	std::cout << "The max profit obtained from the stock days is " << maxProfit(ipVect);
	return 0;
}