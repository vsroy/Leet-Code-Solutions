/*Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/

#include<iostream>
#include<string>

int strStr(std::string haystack, std::string needle) 
{
	if ((haystack == "" && needle == "") || (!haystack.empty() && needle == ""))
		return 0;

	if (haystack.size() < needle.size())
		return -1;

	int needlePointer = 0;
	int matchedChar = 0;
	for (int i = 0; i < haystack.size(); i++)
	{
		for (int j = i; j < haystack.size(); j++)
		{
			char hayStackChar = haystack[j];
			char needleChar = needle[needlePointer];
			if (haystack[j] == needle[needlePointer])
			{
				matchedChar++;
				needlePointer++;
				if (matchedChar == needle.size())
					return i;
			}
			else
			{
				needlePointer = 0;
				matchedChar = 0;
				break;
			}
		}
	}
	return -1;
}

int main()
{
	//std::cout << strStr("hello", "ll");
	//std::cout << strStr("mississippi", "issip");
	std::cout << strStr("aaa", "aaaa");
	return 0;
}