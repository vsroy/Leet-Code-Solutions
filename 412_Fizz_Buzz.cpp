/*Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.*/

#include<iostream>
#include<vector>
#include<string>

class Solution
{
public:
	std::vector<std::string> fizzBuzz(int n) 
	{
		std::vector<std::string> resultVect;
		for (int i = 1; i <= n; i++)
		{
			if ((i % 3 == 0) && (i % 5 != 0))
				resultVect.push_back("Fizz");
			else if ((i % 3 != 0) && (i % 5 == 0))
				resultVect.push_back("Buzz");
			else if ((i % 3 == 0) && (i % 5 == 0))
				resultVect.push_back("FizzBuzz");
			else
				resultVect.push_back(std::to_string(i));
		}
		return resultVect;
	}
};

int main()
{
	Solution s1;
	std::vector<std::string> vectResult = s1.fizzBuzz(15);
	for (int i = 0; i < vectResult.size(); i++)
		std::cout << vectResult[i] << std::endl;
	return 0;
}