#include<iostream>
#include<vector>

/*Function to calculate the best time to buy and sell stock*/
int maxProfit(std::vector<int>& prices) 
{
	if (prices.empty())
		return 0;
	int counter = 0;
	int currentElement = prices[counter];
	int currentProfit = 0;
	int maxProfitSoFar = 0;
	while (counter < prices.size()-1)
	{
		if (currentElement < prices[counter + 1])
		{
			currentProfit = prices[counter + 1] - currentElement;
			if (currentProfit >= maxProfitSoFar)
				maxProfitSoFar = currentProfit;
			counter++;
		}
		else
		{
			currentElement = prices[counter + 1];
			counter++;
		}
	}
	return maxProfitSoFar;
}


int main()
{
	std::vector<int> ipVect{7,1,5,3,6,4};
	std::cout << maxProfit(ipVect);
	return 0;
}