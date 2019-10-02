/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.*/
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

std::vector<int> plusOne(std::vector<int>& digits) 
{
	int carry = 0;
	int vectSize = digits.size();
	if ((digits[vectSize - 1] + 1) == 10)
	{
		digits[vectSize - 1] = 0;
		carry = 1;
	}
	else
		digits[vectSize - 1] += 1;
	for (int i = (vectSize - 2); i >= 0; i--)	/*Traversing the array from the end*/
	{
		if (carry == 1)
		{
			digits[i] += 1;
			if (digits[i] == 10)
			{
				digits[i] = 0;
				carry = 1;
			}
			else
				carry = 0;
		}
		else
			break;
	}
	if (digits[0] == 0)
		digits.insert(digits.begin(),1);
	return digits;
}

int main()
{
	std::vector<int> samplevect = { 2,4,9,3,9 };
	std::vector<int>::iterator it;
	plusOne(samplevect);
	for (it = samplevect.begin(); it != samplevect.end(); it++)
		std::cout << *it << " ";
	return 0;
}