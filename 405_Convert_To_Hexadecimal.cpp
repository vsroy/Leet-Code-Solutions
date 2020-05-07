/*Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string toHex(int num) {
		if (num == 0) return "0";
		string result;
		unsigned int n = num;
		while (n) {
			int remainder = n % 16;
			if (remainder < 10) result += to_string(remainder);
			else {
				result += string(1, 'a' + remainder - 10);
			}
			n /= 16;
		}
		reverse(begin(result), end(result));
		return result;
	}
};


int main()
{
	Solution s1;
	std::cout << s1.toHex(10);
	return 0;
}