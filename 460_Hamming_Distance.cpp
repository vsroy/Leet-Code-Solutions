/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.*/

#include<iostream>
#include<string>

//Function to calculate the Hamming Distance between 2 integers
class Solution 
{
public:
	int hammingDistance(int x, int y) 
	{
		std::string firstBinary = "", secondBinary = "";
		
		//First find out the binary value of the first string
		int remainder = 0, hammingVal = 0;
		while (x != 0)
		{
			remainder = x % 2;
			firstBinary = std::to_string(remainder) + firstBinary;
			x /= 2;
		}
		std::cout << firstBinary << std::endl;

		//First find out the binary value of the second string
		remainder = 0;
		while (y != 0)
		{
			remainder = y % 2;
			secondBinary = std::to_string(remainder) + secondBinary;
			y /= 2;
		}
		std::cout << secondBinary << std::endl;

		if (firstBinary.length() > secondBinary.length())
		{
			int diff = firstBinary.length() - secondBinary.length();
			for (int i = 0; i < diff; i++)
				secondBinary = "0" + secondBinary;
		}

		if (firstBinary.length() < secondBinary.length())
		{
			int diff = secondBinary.length() - firstBinary.length();
			for (int i = 0; i < diff; i++)
				firstBinary = "0" + firstBinary;
		}

		std::cout << firstBinary << std::endl;
		std::cout << secondBinary << std::endl;

		int reverseFirst = firstBinary.length() - 1;
		int reverseSecond = secondBinary.length() - 1;

		while (reverseFirst >=0  && reverseSecond >= 0)
		{
			if (firstBinary[reverseFirst] != secondBinary[reverseSecond])
				hammingVal++;

			reverseFirst--;
			reverseSecond--;
		}
		return hammingVal;
	}
};

int main()
{
	Solution s1;
	std::cout << s1.hammingDistance(1,4);
	return 0;
}