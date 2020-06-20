#include<vector>
#include<iostream>

class Solution 
{
public:
	int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) 
	{
		/*Variable which will store a extra gas for every station taking the starting index station*/
		int extra = 0;

		/*Variable that will store all the total of (difference of gas available at each station and gas require to reach next station)*/
		int total = 0;
		int index = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			/*This will store the difference between gas available and cost for that station*/
			total += gas[i] - cost[i];

			/*This will store whether that station can be a part of the starting station/mid station, if extra < 0, gas will be exhausted here*/
			extra += gas[i] - cost[i];

			/*If gas is exhausted*/
			if (extra < 0)
			{
				/*Reset the gas at this position*/
				extra = 0;
				
				/*We store the next possible starting point*/
				index = i + 1;
			}
		}

		/*Here if this sum total is >=0 ,only then we will have a solution and will return the first index that we have*/
		return ((total >= 0) ? index : -1);
	}
};

int main()
{
	return 0;
}