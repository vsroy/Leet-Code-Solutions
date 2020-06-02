/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution 
{
public:
		vector<string> letterCombinations(string digits) {

			vector<string> result;
			if (!digits.size()) return result;
			result.push_back("");

			vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

			for (int i = 0; i < digits.length(); i++) {
				int current = digits[i] - '0';
				string str = mapping[current];
				vector<string> temp = result;
				result.clear();
				for (int j = 0; j < str.length(); j++) {
					for (int k = 0; k < temp.size(); k++) {
						result.push_back(temp[k] + str[j]);
					}
				}
			}

			return result;
	}
};

int main()
{
	Solution s1; 
	std::vector<std::string> list = s1.letterCombinations("23");
	for (auto i : list)
		std::cout << i << " ";
	return 0;
}