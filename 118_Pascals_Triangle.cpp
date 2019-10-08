#include<iostream>
#include<vector>

/*Function to generate the Pascals triangle*/
std::vector<std::vector<int>> generate(int numRows) 
{
	std::vector<std::vector<int>> pascalVector;

	if (numRows == 0)
		return pascalVector;
	
	pascalVector.push_back(std::vector<int>{1});

	if (numRows == 1)
		return pascalVector;

	pascalVector.push_back(std::vector<int>{1, 1});
	
	if (numRows == 2)
		return pascalVector;
	
	for (int i = 2; i < numRows; i++)	/*Looping through each entry of the result vector*/
	{
		std::vector<int> parentVect = pascalVector[i - 1];	/*Retrieving the parent vector to generate the next vector*/
		std::vector<int> childVect;							/*The new vector that is to be inserted into the pascal triangle*/

		childVect.push_back(1);
		for (int j = 0; j < parentVect.size() - 1; j++)
			childVect.push_back(parentVect[j] + parentVect[j + 1]);
		childVect.push_back(1);
		pascalVector.push_back(childVect);
	}
	return pascalVector;
}

int main()
{
	std::vector<std::vector<int>> resultVect = generate(5);
	for (int i = 0; i < resultVect.size(); i++)
	{
		std::vector<int> childVect = resultVect[i];
		for (int j = 0; j < childVect.size(); j++)
			std::cout << childVect[j] << " ";
		std::cout << std::endl;
	}
	return 0;
}