/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.*/

#include<iostream>
#include<string>

class Solution 
{
public:
	bool canConstruct(std::string ransomNote, std::string magazine) 
	{
		for (int i = 0; i < ransomNote.length(); i++)
		{
			char currChar = ransomNote[i];
			size_t found = magazine.find(currChar);
			if (found == std::string::npos)
				return false;
			else
			{
				magazine[found] = '0';
			}
		}
		return true;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.canConstruct("aa", "aab");
	return 0;
}