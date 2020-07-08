/*A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.*/

#include<iostream>
#include<string>
using namespace std;

class Solution 
{
public:

	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int first = 1, second = 1, temp;

		for (int i = 1; i < s.size(); i++) {
			temp = 0;
			int num = (s[i - 1] - '0') * 10 + (s[i] - '0');

			if (num == 0) return 0;
			if (num >= 10 && num <= 26) temp = first;
			if (num % 10 != 0) temp += second;

			first = second;
			second = temp;
		}
		return second;
	}
};

int main()
{
	Solution s1;
	cout << s1.numDecodings("1234");
	return 0;
}