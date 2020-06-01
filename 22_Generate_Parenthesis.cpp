/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
# define MAX_SIZE 100 

class Solution
{
public:

	void addItem(vector<string> &result, string &tmpString, int pre, int end) 
	{
		if (pre == 0 && end == 0) {
			result.push_back(tmpString);
			return;
		}
		if (pre > 0) {
			tmpString.push_back('(');
			addItem(result, tmpString, pre - 1, end + 1);
			tmpString.pop_back();
		}
		if (end > 0) {
			tmpString.push_back(')');
			addItem(result, tmpString, pre, end - 1);
			tmpString.pop_back();
		}
		return;
	}

	void ParenthesisHelper(int open, int close, int position, std::vector<std::string>& resVect, int n)
	{
		/* Alternate solution
		static char str[MAX_SIZE];
		if (close == n)
		{
			resVect.push_back(str);
			return;
		}
		else
		{
			if (close < open)
			{
				str[position] = '}';
				ParenthesisHelper(open, close + 1, position + 1, resVect, n);
			}

			if (open < n)
			{
				str[position] += '{';
				ParenthesisHelper(open + 1, close, position + 1, resVect, n);
			}
		}
		*/
	}

	
	std::vector<std::string> generateParenthesis(int n) 
	{
		std::vector<std::string> resVect;
		/* Alternate solution
		if (n > 0)
			ParenthesisHelper(0, 0, 0, resVect, n); 
		*/
		if (n <= 0) 
			return resVect;
		string tmpString = "(";
		addItem(resVect, tmpString, n - 1, 1);
		return resVect;
	}
	
};

int main()
{
	Solution s1;
	std::vector<std::string> resVect = s1.generateParenthesis(3);
	for (auto i : resVect)
		std::cout << i << std::endl;
	return 0;
}