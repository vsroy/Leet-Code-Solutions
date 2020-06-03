/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
public:
	string longestPalindrome(string s) {
		string ans = "";
		if (s.empty())
		{
			return ans;
		}
		int maxl = 1;
		int low;
		int high;
		int start = 0; //starting point of palindromic substring 
		for (int i = 1; i<s.length(); i++)
		{
			//checking for even length palindromes having two centers...
			low = i - 1;
			high = i;
			while (low >= 0 && high<s.length() && (s[low] == s[high]))
			{
				if ((high - low + 1)> maxl)
				{
					maxl = high - low + 1;
					start = low;
				}
				low--;
				high++;
			}

			//checking for odd length palindromes..
			low = i - 1;
			high = i + 1;
			while (low >= 0 && high<s.length() && (s[low] == s[high]))
			{
				if ((high - low + 1)> maxl)
				{
					maxl = high - low + 1;
					start = low;
				}
				low--;
				high++;
			}
		}
		for (int i = start; i <= (maxl + start - 1); i++)
		{
			ans.push_back(s[i]);
		}
		return ans;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.longestPalindrome("aaaa");
	return 0;
}