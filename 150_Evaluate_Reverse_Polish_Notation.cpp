/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

class Solution 
{
public:
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> notationStack;
		int result = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+")
			{
				int digit1; int digit2; digit2 = notationStack.top(); notationStack.pop(); digit1 = notationStack.top(); notationStack.pop();
				notationStack.push(digit1 + digit2);
			}

			else if (tokens[i] == "-")
			{
				int digit1; int digit2; digit2 = notationStack.top(); notationStack.pop(); digit1 = notationStack.top(); notationStack.pop();
				notationStack.push(digit1 - digit2);
			}

			else if (tokens[i] == "*")
			{
				int digit1; int digit2; digit2 = notationStack.top(); notationStack.pop(); digit1 = notationStack.top(); notationStack.pop();
				notationStack.push(digit1 * digit2);
			}

			else if (tokens[i] == "/")
			{
				int digit1; int digit2; digit2 = notationStack.top(); notationStack.pop(); digit1 = notationStack.top(); notationStack.pop();
				notationStack.push(digit1 / digit2);
			}
			
			else
			{
				int digit = 0;
				stringstream ss(tokens[i]);
				ss >> digit;
				notationStack.push(digit);
			}
		}
		return notationStack.top();
	}
};

int main()
{
	Solution s1;
	vector<string> ipVect{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	std::cout << s1.evalRPN(ipVect);
	return 0;
}