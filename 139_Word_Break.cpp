/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.*/
#include<vector>
#include<iostream>


class Solution 
{
public:
	bool wordBreak(std::string s, std::vector<std::string>& wordDict) 
	{
		int dpSize = s.size();

		/*Initializing the set of zeroes*/
		std::vector<int> dpVect(dpSize + 1);
		dpVect[0] = 1;

		for (int i = 1; i <= dpSize; ++i)
		{
			/*We check first that we start from the end of the substring found in the string */
			if (dpVect[i - 1] == 1)
			{
				/*Loop through every word in the dict and check occurrence of that in the main string*/
				for (auto& word : wordDict)
				{
					int wordSize = word.size();

					/*If word matches, mark the end of the substring as 1 so that we can contine to validate from end of the substring*/
					if (s.substr(i - 1, wordSize) == word)
						dpVect[i - 1 + wordSize] = 1;
				}
			}
		}
		return dpVect[dpSize];
	}
};

int main()
{
	Solution s1;
	std::vector<std::string> ipVect{ "leet", "code" };
	std::cout << s1.wordBreak("leetcode",ipVect);
	return 0;
}