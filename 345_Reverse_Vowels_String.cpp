#include<iostream>
#include<string>

class Solution 
{
public:
	std::string reverseVowels(std::string s) 
	{
		int start = 0;
		int end = s.length() - 1;
		while (start != end && start < end)
		{
			char startChar = s[start];
			char endChar = s[end];
			if ((startChar == 'a' || startChar == 'e' || startChar == 'i' || startChar == 'o' || startChar == 'u'
				|| startChar == 'A' || startChar == 'E' || startChar == 'I' || startChar == 'O' || startChar == 'U') &&
				(endChar == 'a' || endChar == 'e' || endChar == 'i' || endChar == 'o' || endChar == 'u'
				|| endChar == 'A' || endChar == 'E' || endChar == 'I' || endChar == 'O' || endChar == 'U'))
			{
				char temp = s[start];
				s[start] = s[end];
				s[end] = temp;
				start++; end--;
			}
			else if ((startChar == 'a' || startChar == 'e' || startChar == 'i' || startChar == 'o' || startChar == 'u'
				|| startChar == 'A' || startChar == 'E' || startChar == 'I' || startChar == 'O' || startChar == 'U'))
			{
				end--;
			}
			else if (endChar == 'a' || endChar == 'e' || endChar == 'i' || endChar == 'o' || endChar == 'u'
				|| endChar == 'A' || endChar == 'E' || endChar == 'I' || endChar == 'O' || endChar == 'U')
			{
				start++;
			}
			else
			{
				start++; end--;
			}
		}
		return s;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.reverseVowels("leetcode");
	return 0;
}