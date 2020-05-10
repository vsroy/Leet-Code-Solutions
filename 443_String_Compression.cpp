/*Given an array of characters, compress it in-place.
The length after compression must always be smaller than or equal to the original array.
Every element of the array should be a character (not int) of length 1.
After you are done modifying the input array in-place, return the new length of the array.*/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Solution 
{
public:
	int compress(std::vector<char>& chars) 
	{
		if (chars.size() == 1)
			chars.size();

		string str;
		for (int i = 0; i < chars.size(); i++)
		{
			int count = 1;
			int j = i;
			while (j + 1 != chars.size() && chars[i] == chars[j + 1])
			{
				count++;
				j++;
			}

			str += chars[i];
			if (count > 1)
			{
				str += to_string(count);
			}
			i = i + count - 1;
		}

		chars.clear();
		for (const auto& ch : str)
			chars.push_back(ch);
		return chars.size();
	}
};

int main()
{
	Solution s1;
	std::vector<char> vectChar{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	std::cout << s1.compress(vectChar);
	return 0;
}