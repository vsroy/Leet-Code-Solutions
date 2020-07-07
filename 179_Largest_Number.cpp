/*Given a list of non negative integers, arrange them such that they form the largest number.*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

class Solution 
{
public:

	/*In the used sorting algorithm, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.
	Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) and 
	YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before.*/

	static int myCompare(string x, string y)
	{
		string xy = x + y;
		string yx = y + x;
		if (xy.compare(yx) > 0)
			return 1;
		else
			return 0;
	}

	string largestNumber(vector<int>& nums) 
	{
		int zeroCount = 0;
		vector<string> ipString;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				zeroCount++;
			stringstream ss;
			ss << nums[i];
			ipString.push_back(ss.str());
		}

		/*Check for all zeroes in the string*/
		if (zeroCount == nums.size())
			return "0";

		string result = "";
		sort(ipString.begin(), ipString.end(), myCompare);
		for (int i = 0; i < ipString.size(); i++)
			result += ipString[i];
		return result;
	}
};

int main()
{
	Solution s1;
	vector<int> ipVect{ 0 };
	cout << s1.largestNumber(ipVect);
	return 0;
}