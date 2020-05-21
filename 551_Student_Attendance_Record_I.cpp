/*You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.*/

#include<iostream>
#include<string>

class Solution 
{
public:
	bool checkRecord(std::string s) 
	{
		int absentCount = 0;
		if (s.find("LLL") != std::string::npos)
			return false;
		
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'A')
				absentCount++;
			if (absentCount > 1)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.checkRecord("APALL");
	return 0;
}