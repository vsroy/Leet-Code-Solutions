/*Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.*/
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;


std::string addBinary(std::string a, std::string b) 
{
	string res;
	int i = a.size() - 1, j = b.size() - 1;
	int carry = 0;
	while (carry || i >= 0 || j >= 0)
	{
		int num1 = 0, num2 = 0;
		if (i >= 0)
			num1 = a[i--] - '0';
		if (j >= 0)
			num2 = b[j--] - '0';
		int sum = num1 + num2 + carry;
		res.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	std::string a = "11";
	std::string b = "1";
	std::cout << addBinary(a,b);
	return 0;
}