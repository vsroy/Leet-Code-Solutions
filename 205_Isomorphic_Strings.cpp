#include<iostream>
#include<string>
#include<map>
#include<set>

bool isIsomorphic(std::string s, std::string t) 
{
	std::set<char> isoSet;
	std::map<char, char> isoMap;
	if (s.length() != t.length())
		return false;
	for (int i = 0; i < s.length(); i++)
	{
		if (isoMap.find(s[i]) != isoMap.end())
		{
			if (isoMap[s[i]] != t[i])
				return false;
		}
		else
		{
			if (isoSet.find(t[i]) != isoSet.end())
				return false;
			else
			{
				isoMap[s[i]] = t[i];
				isoSet.insert(t[i]);
			}
		}
			
	}
	return true;
}

int main()
{
	std::cout << isIsomorphic("ab","aa");
	return 0;
}