/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*/
#include<iostream>
#include<vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{
	std::vector<int> resultVector;
	int vect1Pos = 0;
	int vect2Pos = 0;
	int resultPos = 0;
	while ((vect1Pos < m) && (vect2Pos < n))
	{
		if (nums1[vect1Pos] < nums2[vect2Pos])
		{
			resultVector.push_back(nums1[vect1Pos]);
			vect1Pos++;
		}
		else
		{
			resultVector.push_back(nums2[vect2Pos]);
			vect2Pos++;
		}
	}

	if (vect1Pos < m)
	{
		while (vect1Pos < m)
		{
			resultVector.push_back(nums1[vect1Pos]);
			vect1Pos++;
		}
	}

	if (vect2Pos < n)
	{
		while (vect2Pos < n)
		{
			resultVector.push_back(nums2[vect2Pos]);
			vect2Pos++;
		}
	}
	nums1 = resultVector;
}


int main()
{
	std::vector<int> vect1 = { 1, 2, 3, 0, 0, 0 };
	std::vector<int> vect2 = { 2, 5, 6 };
	merge(vect1,3,vect2,3);
	for (int i = 0; i < vect1.size(); i++)
		std::cout << vect1[i] << " ";
	return 0;
}