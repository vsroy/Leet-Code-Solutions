/*Compute and return the square root of x, where x is guaranteed to be a non-negative longeger.
*/
#include<iostream>

long mySqrt(long x) 
{
	if (x == 0 || x == 1)
		return x;
	long start = 0; long end = x, ans;
	while (start <= end)
	{
		long mid = (start + end) / 2;
		
		if (mid*mid == x)
			return mid;

		if (mid*mid < x)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return ans;
}

long main()
{
	std::cout << mySqrt(6);
	return 0;
}