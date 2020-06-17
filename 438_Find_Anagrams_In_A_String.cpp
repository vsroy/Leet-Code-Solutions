#include<iostream>
#include<vector>
#include<string>


class Solution 
{
public:
	std::vector<int> findAnagrams(std::string s, std::string p) 
	{
		if (s.length() == 0 || p.length() == 0)
			return{};
		if (p.length() > s.length())
			return{};

		int longLength = s.size();
		int shortLength = p.size();

		std::vector<int> longVect(26);
		std::vector<int> shortVect(26);

		for (int i = 0; i < shortLength; i++)
		{
			longVect[s[i] - 'a']++;
			shortVect[p[i] - 'a']++;
		}
		std::vector<int> resultVect;

		/*We iterate thorugh the array. Each iteration will be a sliding window*/
		for (int i = 0; i <= longLength - shortLength; i++)
		{
			if (shortVect == longVect)
				resultVect.push_back(i);
			if (i < (longLength - shortLength))
			{
				/*Taking the next character ins superstring in sliding window*/
				longVect[s[i + shortLength]-'a']++;

				/*Removing the previous character in the sliding window*/
				longVect[s[i] - 'a']--;
			}
		}
		return resultVect;
	}
};


int main()
{
	Solution s1;
	std::vector<int> resultVect = s1.findAnagrams("cbaebabacd","abc");

	for (auto i : resultVect)
		std::cout << i << " ";
	return 0;
}