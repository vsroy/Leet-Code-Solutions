#include<iostream>
#include<vector>

class Solution 
{
public:
	void reverseString(std::vector<char>& s) 
	{
		int start = 0, end = s.size() - 1;
		while (start != end && start < end)
		{
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++; end--;
		}
	}
};


int main()
{
	std::vector<char> vect1{'H','a','n','n','a','h'};
	Solution s1;
	s1.reverseString(vect1);
	for (int i = 0; i < vect1.size(); i++)
		std::cout << vect1[i] << " ";
	return 0;
}