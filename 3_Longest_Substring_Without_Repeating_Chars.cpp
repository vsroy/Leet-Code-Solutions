/*Given a string, find the length of the longest substring without repeating characters.*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#define NO_OF_CHARS 256

class Solution 
{
public:
	int lengthOfLongestSubstring(std::string s) 
	{
		int n = s.size();

		/*Initialzing all the last index of all chars to -1*/
		std::vector<int> lastIndex(NO_OF_CHARS, -1);

		/*Initialize the start of the current window*/
		int i = 0;

		/*The result*/
		int res = 0;

		/*Move the end of the current window. So here, we keep 2 pointers i and j*/
		for (int j = 0; j < n; j++)
		{
			/*If we find previous occurrence of the current char, the start of the window will be max of i or last index of the current char*/
			i = std::max(lastIndex[s[j]]+1, i);

			/*In case we get a result greater than the last one*/
			res = std::max(res, j - i + 1);

			/*Update the last index of j*/
			lastIndex[s[j]] = j;
		}
		return res;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.lengthOfLongestSubstring("abcabcbb");
	return 0;
}