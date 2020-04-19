/*You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.*/

#include<iostream>
#include<vector>

class Solution 
{
private:
	int *versionsArr;

public:
	Solution()
	{
		versionsArr = new int[5]{0,0,0,1,1};
	}

	bool isBadVersion(int n)
	{
		return versionsArr[n];
	}

	int firstBadVersion(int n)
	{
		int index;
		int low = 0;
		int high = n;
		int mid;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (isBadVersion(mid))
			{
				index = mid;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return index;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.firstBadVersion(5);
	return 0;
}