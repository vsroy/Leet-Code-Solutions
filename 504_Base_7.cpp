/*Given an integer, return its base 7 string representation.*/

#include<string>
#include<iostream>

class Solution 
{
public:
	std::string convertToBase7(int num) 
	{
		int originalVal = num;
		std::string base7 = "";
		while (num / 7 != 0)
		{
			int rem = abs(num % 7);
			base7 = std::to_string(rem) + base7;
			num = abs(num / 7);
		}
		base7 = std::to_string(num) + base7;
		
		if (originalVal < 0)
			base7 = '-' + base7;
		
		return base7;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.convertToBase7(-1);
	return 0;
}