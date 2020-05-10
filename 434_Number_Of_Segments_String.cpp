/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters.*/

#include<iostream>
#include<string>

class Solution 
{
public:
	int countSegments(std::string s) 
	{
		if (s == "")
			return 0;

		int segmentCount = 0;
		for (int i = 0; i < s.length(); i++)
			if ((s[i] != ' ' && s[i + 1] == ' ') || (s[i] != ' ' && ((i + 1) == s.length())))
				segmentCount++;
		/*
		if (spaceCount == s.length())
			return 0;
		else
		*/
		if (segmentCount == 0)
			return 0;
		else
			return ++segmentCount;
	}
};

int main()
{
	Solution s1;
	//std::cout << s1.countSegments("Hello, my name is John");
	std::cout << s1.countSegments("Hello");
	return 0;
}