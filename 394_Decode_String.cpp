/*Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string 
inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.*/

#include<iostream>
#include<string>
#include<stack>
#include<sstream>

class Solution 
{
public:
	std::string decodeString(std::string s) 
	{
		std::stack<char> decodeStack;	//"abc3[cd]xyz"
		std::string resultString = "";

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ']')
				decodeStack.push(s[i]);
			else
			{
				std::string tempString = "";
				while (decodeStack.top() != '[')
				{
					tempString = decodeStack.top() + tempString;
					decodeStack.pop();
				}
				decodeStack.pop();	/*Popping '['*/
				int intChar = int(decodeStack.top());
				std::string strMultiplier = "";
				while (!decodeStack.empty() && (int(decodeStack.top() >= 48)) && (int(decodeStack.top() <= 57)))
				{
					strMultiplier = decodeStack.top() + strMultiplier;
					decodeStack.pop();
				}
				int val = 0;
				std::stringstream ss(strMultiplier);
				ss >> val;
				for (int i = 1; i <= val; i++)
					resultString = resultString + tempString;
				for (int i = 0; i < resultString.size(); i++)
					decodeStack.push(resultString[i]);
				resultString = "";
			}
		}
		while (!decodeStack.empty())
		{
			resultString = decodeStack.top() + resultString;
			decodeStack.pop();
		}
		return resultString;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.decodeString("3[a2[c]]");
	return 0;
}