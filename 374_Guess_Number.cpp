#include<iostream>

class Solution 
{
	int actualNumber = 10;
public:

	int guess(int num)
	{
		if (num < 10)
			return -1;
		else if (num > 10)
			return 1;
		else
			return 0;
	}

	/*The function that will return the guessed number*/
	int guessNumber(int n) 
	{
		int left = 0, right = n;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int ans = guess(mid);
			if (ans == 0)
				return mid;
			else if (ans == -1)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return left;
	}
};

int main()
{
	return 0;
}