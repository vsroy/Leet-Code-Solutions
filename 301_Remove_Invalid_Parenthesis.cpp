/*Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>

using namespace std;
class Solution 
{
public:

	/*Checks if a character is valid open or close brackets*/
	bool IsParenthesis(char c)
	{
		if (c == '(' || c == ')')
			return true;
		else
			return false;
	}

	/*Checks if a string forms a valid parenthesis string*/
	bool IsValidString(string s)
	{
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				count++;
			else if (s[i] == ')')
				count--;
			if (count < 0)
				return false;
		}
		return (count == 0);
	}

	vector<string> removeInvalidParentheses(string s)
	{
		vector<string> result;

		if (s.empty())
			return{""};

		/*Container to store all the visited strings*/
		set<string> visited;

		/*Queue to maintain all the BFS traversals of trees*/
		queue<string> q;

		string temp;
		bool level = false;

		q.push(s);
		visited.insert(s);
		
		while (!q.empty())
		{
			s = q.front();
			q.pop();

			if (IsValidString(s))
			{
				result.push_back(s);
				level = true;
			}
			if (level)
				continue;

			for (int i = 0; i < s.length(); i++)
			{
				if (!IsParenthesis(s[i]))
					continue;

				temp = s.substr(0, i) + s.substr(i + 1);
				if (visited.find(temp) == visited.end())
				{
					q.push(temp);
					visited.insert(temp);
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s1;
	auto i = s1.removeInvalidParentheses("()())()");
	for (auto j : i)
		std::cout << j << std::endl;
	return 0;
}