/*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.*/

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

class Solution 
{
public:
	int longestValidParentheses(std::string s) 
	{
		if (s.empty())
			return 0;
		std::stack<int> parStack;
		parStack.push(-1);
		int maxLen = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				parStack.push(i);
			else
			{
				parStack.pop();

				if (!parStack.empty())
					maxLen = std::max(maxLen, i - parStack.top());
				else
					parStack.push(i);
			}
		}
		return maxLen;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.longestValidParentheses("(()");
	return 0;
}