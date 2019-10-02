/*https://leetcode.com/problems/longest-common-prefix/*/
/*Write a function to find the longest common prefix string amongst an array of strings.*/
#include<iostream>
#include<string>
#include<vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) 
{
	std::string result = "";
	int count = strs.size();
	int smallestSize = INT_MAX;
	for (int i = 0; i < strs.size(); i++)	/*Gets the length of the smallest string*/
	{
		if (strs[i].length() < smallestSize)
			smallestSize = strs[i].length();
	}

	for (int i = 0; i < smallestSize; i++)	/*Looping over the elements*/
	{
		int sum = 0;
		char currChar;
		int charVal;
		for (int j = 0; j < count; j++)
		{
			std::string currString = strs[j];
			charVal = int((strs[j])[i]) - 96;	/*This gives us the value of the char in the string*/
			sum = sum + charVal;
			currChar = (strs[j])[i];
		}
		if ((sum / charVal) == count)
		{
			result = result + currChar;
		}
		else
			break;
	}
	return result;
}

int main()
{
	std::vector<std::string> strs;
	/*
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");
	*/

	strs.push_back("dog");
	strs.push_back("racecar");
	strs.push_back("car");

	std::cout << longestCommonPrefix(strs);
	return 0;
}