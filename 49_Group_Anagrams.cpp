/*Given an array of strings, group anagrams together.*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		/*This will store the sorted strings and the words associated with the string*/
		map<string, vector<string>> anagramMap;

		for (int i = 0; i < strs.size(); i++)
		{
			string currChar = strs[i];
			sort(currChar.begin(), currChar.end());	
			anagramMap[currChar].push_back(strs[i]);
		}

		vector<vector<string>> resultVect;
		
		map<string, vector<string>>::iterator it;
		for (it = anagramMap.begin(); it != anagramMap.end(); it++)
		{
			resultVect.push_back(it->second);
		}
		return resultVect;
	}
};

int main()
{
	Solution s1;
	vector<string> ipVect = { "eat", "tea", "tan", "ate", "nat", "bat" };

	vector<vector<string>> resultString = s1.groupAnagrams(ipVect);

	for (auto i : resultString)
	{
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}