#include<iostream>
#include<stdint.h>
#include<vector>

int hammingWeight(uint32_t n) 
{
	std::vector<int> binaryVector;
	while (n > 0)
	{
		binaryVector.push_back(n % 2);
		n /= 2;
	}

	int onesCount = 0;
	for (int i = 0; i < binaryVector.size(); i++)
	{
		if (binaryVector[i] == 1)
			onesCount++;
	}
	return onesCount;
}

int main()
{
	std::cout << hammingWeight(20);
	return 0;
}