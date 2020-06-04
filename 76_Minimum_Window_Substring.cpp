#include<iostream>
#include<string>
#include<vector>

class Solution 
{
public:
	std::string minWindow(std::string s, std::string t) 
	{
		/*Array of integers that will store the occurrences of the characters*/
		std::vector<int> mainArray(256);
		std::vector<int> patternArray(256);

		/*For every char in pattern string, increment the count of that character by 1*/
		for (int i = 0; i < t.length(); i++)
			patternArray[t[i]]++;

		int count = 0;
		int start = 0, start_index = -1, min_len = INT_MAX;
		
		/*Iterate through the main array and check if a character matches the pattern array*/
		for (int i = 0; i < s.length(); i++)
		{
			mainArray[s[i]]++;

			/*If the current element is present in the pattern and character count in current window does not exceed the char count in the pattern*/
			if ((patternArray[s[i]] != 0) && (mainArray[s[i]] <= patternArray[s[i]]))
				count++;

			/*If all the characters are matched*/
			if (count == t.size())
			{
				/*Try to minimize the window. Remove any extra elements from the start present in the count array of the main array*/
				while ((mainArray[s[start]] > patternArray[s[start]]) || (patternArray[s[start]] == 0))
				{
					if (mainArray[s[start]] > patternArray[s[start]])
						mainArray[s[start]]--;
					start++;
				}

				/*Update the window size*/
				int window_length = i - start + 1;

				if (window_length < min_len)
				{
					min_len = window_length;
					start_index = start;
				}
			}
		}

		/*If no window found*/
		if (start_index == -1)
			return "";
		return s.substr(start_index, min_len);
	}	
};

int main()
{
	Solution s1;
	std::cout << s1.minWindow("ADOBECODEBANC", "ABC");
	return 0;
}