/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.*/
#include<iostream>
#include<string>
#include<stack>

bool isValid(std::string s) 
{
	std::stack<char> charStack;
	for (int i = 0; i < s.size(); i++)
	{
		char currChar = s[i];
		
		if (currChar == '[' || currChar == '{' || currChar == '(')
		{
			charStack.push(currChar);
		}
		else
		{
			if (charStack.empty())
				return false;
			else
			{
				switch (currChar)
				{
				case ']':
					if (charStack.top() == '[')
					{
						charStack.pop();
						break;
					}
					else
						return false;

				case '}':
					if (charStack.top() == '{')
					{
						charStack.pop();
						break;
					}
					else
						return false;

				case ')':
					if (charStack.top() == '(')
					{
						charStack.pop();
						break;
					}
					else
						return false;

				default:
					break;
				}
			}
		}
	}
	return charStack.empty() ? true : false;
}

int main()
{
	std::cout << isValid("()");
	std::cout << isValid("()[]{}");
	std::cout << isValid("(]");
	std::cout << isValid("([)]");
	std::cout << isValid("{[]}");
	return 0;
}

