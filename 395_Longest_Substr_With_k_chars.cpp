/*Find the length of the longest substring T of a given string (consists of lowercase letters only) 
such that every character in T appears no less than k times.*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	int longestSubstring(string s, int k) 
	{
		/*Base case - When a solution is not possible*/
		if (s.length() < k)
			return 0;

		/*Initialzing to keep track of the counts of each char in the string*/
		int counts[26] = {0,};
		for (int i = 0; i < s.length(); i++)
			counts[s[i] - 'a']++;

		/*Traversing through the string will we find a character less than the count*/
		int i = 0;
		while (i < s.length() && counts[s[i] - 'a'] >= k)
			i++;

		if (i == s.length())
			return s.length();

		/*If recurse for the left and right substring of the element*/
		return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1), k));
	}
};

int main()
{
	Solution s1;
	std::cout << s1.longestSubstring("ababbc",2);
	return 0;
}