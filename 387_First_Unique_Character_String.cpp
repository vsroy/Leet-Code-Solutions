/*Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.*/

#include<iostream>
#include<string>
#include<unordered_map>

class Solution 
{
public:
	int firstUniqChar(std::string s)
	{
		std::unordered_map<char, int> stringMap;
		for (int i = 0; i < s.length(); i++)
			stringMap[s[i]]++;

		std::unordered_map<char, int>::iterator it;

		/*
		for (it = stringMap.begin(); it != stringMap.end(); it++)
		{
			std::cout << it->first << " " << it->second << std::endl;
		}
		*/

		for (int i = 0; i < s.size(); i++)
		{
			char currChar = s[i];
			if (stringMap[currChar] == 1)
				return i;
		}
		return -1;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.firstUniqChar("loveleetcode");
	return 0;
}