/*Given a pattern and a string str, find if str follows the same pattern.*/

#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int i = 0, j = 0;
		unordered_map<string, char> m;
		set<char>c;
		if (str.length() == 0 || pattern.length() == 0)
			return false;

		while (j<pattern.length())
		{
			if (i >= str.length())
				return false;
			string s = "";
			while (str[i] != ' ' && i<str.length())
			{
				s += str[i];
				i++;
			}
			if (m.find(s) == m.end())
			{

				if (c.find(pattern[j]) != c.end())
					return false;
				m[s] = pattern[j];
				c.insert(pattern[j]);
				j++; i++;
			}
			else
			{
				if (m[s] == pattern[j])
				{
					j++; i++;
				}

				else return false;
			}

		}
		if (i<str.length())
			return false;
		return true;
	}
};

int main()
{
	Solution s1;
	cout << s1.wordPattern("abba", "dog dog dog dog");
	return 0;
}