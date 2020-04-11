#include<iostream>
#include<map>
using namespace std;

class Solution 
{
public:
	bool isAnagram(string s, string t) 
	{
		map<char, int> map1;
		map<char, int> map2;

		if (s.length() != t.length())
			return false;
		
		for (int i = 0; i < s.length(); i++)
		{
			map1[s[i]]++;
			map2[t[i]]++;
		}

		//map<char, int>::iterator it1;

		/*
		for (it = map1.begin(); it != map1.end(); it++)
		{
			std::cout << it->first << " " << it->second << endl;
		}

		std::cout << endl;

		for (it = map2.begin(); it != map2.end(); it++)
		{
			std::cout << it->first << " " << it->second << endl;
		}
		*/

		map<char, int>::iterator it1 = map1.begin();
		map<char, int>::iterator it2 = map2.begin();

		while (it1 != map1.end() || it2 != map2.end())
		{
			if (it1->first != it2->first)
				return false;
			if (it1->second != it2->second)
				return false;
			it1++; it2++;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	cout << sol.isAnagram("rat", "car");
	return 0;
}