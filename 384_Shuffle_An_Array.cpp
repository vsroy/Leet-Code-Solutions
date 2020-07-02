/*Shuffle a set of numbers without duplicates.*/
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> temp1;
	vector<int> temp2;

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	Solution(vector<int>& nums) 
	{
		temp1 = nums;
		temp2 = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() 
	{
		temp2 = temp1;
		return temp2;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() 
	{
		for (int i = 0; i < temp2.size(); i++)
			swap(temp2[i], temp2[rand() % temp2.size()]);
		return temp2;
	}
};

int main()
{

	return 0;
}