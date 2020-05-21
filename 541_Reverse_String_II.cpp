/*Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:

	void reverse(string& s, int i, int j)
	{
		while (i < j)
		{
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
			i++, j--;
		}
	}

	string reverseStr(string s, int k) {
		int i = 0;
		int j = 1;
		while (i < s.size())
		{
			int pos = (2 * k*j) - 1;
			if (i == pos)
			{
				int start = i - ((2 * k) - 1); //Start index of string rotation.
				int end = i - k;            //End index of string rotation.    
				reverse(s, start, end);
				j++;
			}
			i++;
		}

		//Work on the leftover part.
		int leftover = i % (2 * k);
		if (leftover != 0)
		{
			if (leftover >= k)   //More than k char 
				reverse(s, s.size() - leftover, s.size() - leftover + k - 1);
			else
				reverse(s, s.size() - leftover, s.size() - 1);  //Reverse if less than k chars remaining.
		}

		return s;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.reverseStr("abcdefg",2);
	return 0;
}