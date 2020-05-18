/*Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.*/


#include<iostream>
#include<map>


int main()
{
	std::map<int, int>::iterator it;
	std::map<int, int> findNode;
	for (it = findNode.begin(); it != findNode.end(); it++)
	{
		std::cout << it->first << " " << it->second;
	}

	std::map<int, int>* temp = &findNode;

	(*temp)[0]++;
	findNode[0]++;

	for (it = findNode.begin(); it != findNode.end(); it++)
	{
		std::cout << it->first << " " << it->second;
	}

	return 0;
}