/*Given a non negative integer number num. For every numbers i in the range 
0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	std::vector<int> countBits(int num) 
	{
		/*Initialize the vector*/
		std::vector<int> bitVect(num + 1);

		/*We will use tabulation to store the number of bits so far and proceed accordingly*/
		/*Loop from 0 to num*/
		for (int i = 0; i <= num; i++)
			bitVect[i] = bitVect[i / 2] + (i % 2);

		return bitVect;
	}
};

int main()
{
	Solution s1;
	std::vector<int> reVect = s1.countBits(5);

	for (auto i : reVect)
		std::cout << i << " ";
	return 0;
}