#include<iostream>
#include<vector>

/*Function to generate the Pascals triangle*/
std::vector<int> generate(int rowIndex)
{
	std::vector<std::vector<int>> pascalVector;

	if (rowIndex == 0)
		return std::vector<int>{1};

	pascalVector.push_back(std::vector<int>{1});

	if (rowIndex == 1)
		return std::vector<int>{1,1};

	pascalVector.push_back(std::vector<int>{1, 1});

	for (int i = 2; i <= rowIndex; i++)	/*Looping through each entry of the result vector*/
	{
		std::vector<int> parentVect = pascalVector[i - 1];	/*Retrieving the parent vector to generate the next vector*/
		std::vector<int> childVect;							/*The new vector that is to be inserted into the pascal triangle*/

		childVect.push_back(1);
		for (int j = 0; j < parentVect.size() - 1; j++)
			childVect.push_back(parentVect[j] + parentVect[j + 1]);
		childVect.push_back(1);
		pascalVector.push_back(childVect);
	}
	return pascalVector[rowIndex];
}

int main()
{
	std::vector<int> pascalVector = generate(3);
	std::vector<int>::iterator it;
	for (it = pascalVector.begin(); it != pascalVector.end(); it++)
		std::cout << *it << " ";
	return 0;
}