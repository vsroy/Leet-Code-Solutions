/*You are given a license key represented as a string S which consists only alphanumeric character and dashes. 
The string is separated into N+1 groups by N dashes.
Given a number K, we would want to reformat the strings such that each group contains exactly K characters, 
except for the first group which could be shorter than K, but still must contain at least one character. 
Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.
Given a non-empty string S and a number K, format the string according to the rules described above.*/

#include<iostream>
#include<string>
#include<ctype.h>
#include<stdio.h>
#include<stack>
using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		stack<char> sChars;
		for (auto ch : S) {
			if (ch != '-')
				sChars.push(ch);
		}

		string sRet;
		int cur = 0;
		while (!sChars.empty()) {
			sRet += toupper(sChars.top());
			sChars.pop();
			cur++;

			if (cur == K && !sChars.empty()) {
				sRet += '-';
				cur = 0;
			}
		}
		reverse(sRet.begin(), sRet.end());
		return sRet;
	}
};

int main()
{
	Solution s1;
	//std::cout << s1.licenseKeyFormatting("5F3Z-2e-9-w",4);
	std::cout << s1.licenseKeyFormatting("--a-a-a-a--", 2);
	return 0;
}