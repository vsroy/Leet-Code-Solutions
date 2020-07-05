/*Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.*/


/*Use two stacks : one to save operators, one to save oprands. Every time, if we get a digit, then update curNum, 
if we get an operator, then it means we get a complete oprand, which is saved in curNum; if the last operator is * or /, then calculate it, 
otherwise, just save curNum and s[i] (new operator) in the stacks. At last, the opS stack 
has only "+" & "-", which are the sign of the corresponding operands saved in numS. Then we do sum to get the result.*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution 
{
public:
	int calculate(std::string s) 
	{
		stack<char> opS;
		stack<int>  numS;
		s.push_back(')'); // to make sure the last operand will be saved in the stack e.g. 1+2*3), 2*3 will be calculated and push in the stack
		opS.push('+'); // sign for the first operand

		int i, curNum, len = s.size(), res = 0;
		for (i = 0, curNum = 0; i<len; ++i)
		{
			if (isdigit(s[i])) curNum = curNum * 10 + s[i] - '0'; // digit, recover the oprand
			else if (isspace(s[i])) continue; // skip the space
			else
			{
				switch (opS.top())
				{
				case '*': // if the last operator is * / , do calculation
				case '/':
					curNum = opS.top() == '/' ? numS.top() / curNum : numS.top()*curNum;
					opS.pop();
					numS.pop();
				}
				numS.push(curNum); 
					curNum = 0;
				opS.push(s[i]);
			}
		}
		opS.pop(); // skip the ")"
		while (!opS.empty()) { res += (opS.top() == '-') ? -numS.top() : numS.top(); opS.pop(); numS.pop(); }
		return res;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.calculate("3+2*2");
	return 0;
}