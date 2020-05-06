/*Given a string s and a string t, check if s is subsequence of t.*/

#include<iostream>
#include<string>

class Solution 
{
public:
	bool isSubsequence(std::string s, std::string t) 
	{
		if (s == "")
			return true;
		int tRunner = 0, sRunner = 0;
		while (tRunner < t.length())
		{
			if (s[sRunner] == t[tRunner])
			{
				sRunner++;
				if (sRunner == (s.length()))
					return true;
			}
			tRunner++;
			
		}
		return false;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.isSubsequence("abc", "ahbgdc");
	return 0;
}