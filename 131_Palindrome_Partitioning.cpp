/*Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.*/

#include<iostream>
#include<vector>

class Solution 
{
	std::vector<std::vector<std::string>> result;

	/*Function to check whether a string is a plaindrome*/
	bool IsPalindrome(std::string str)
	{
		std::string temp = str;
		std::reverse(str.begin(), str.end());
		return (temp == str ? true : false);
	}

public:
	void helperPalindromeFunction(std::string str,int pos, std::vector<std::string> v)
	{
		if (pos > str.length())
			return;

		if (pos == str.length())
		{
			result.push_back(v);
			return;
		}

		int i;
		for (int i = 1; i <= str.length()-pos; i++)
		{
			std::string s1 = str.substr(pos, i);
			if (IsPalindrome(s1))
			{
				v.push_back(s1);
				helperPalindromeFunction(str,pos+i,v);
				v.pop_back();
			}
		}
	}

	std::vector<std::vector<std::string>> partition(std::string s) 
	{
		std::vector<std::string> ipVect;
		helperPalindromeFunction(s,0,ipVect);
		return result;
	}
};

int main()
{
	Solution s1;
	std::vector<std::vector<std::string>> result = s1.partition("nitin");

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}