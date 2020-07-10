/*There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> tempVect;
		int size1 = nums1.size();
		int size2 = nums2.size();

		int i = 0, j = 0;
		
		while (i < size1 && j < size2)
		{
			if (nums1[i] < nums2[j])
			{
				tempVect.push_back(nums1[i]);
				i++;
			}
			else
			{
				tempVect.push_back(nums2[j]);
				j++;
			}
		}
		while (i < size1)
		{
			tempVect.push_back(nums1[i]);
			i++;
		}

		while (j < size2)
		{
			tempVect.push_back(nums2[j]);
			j++;
		}

		if (tempVect.size() % 2 != 0)
		{
			return tempVect[tempVect.size() / 2];
		}
		else
		{
			int index1 = tempVect.size() / 2 - 1;
			int index2 = tempVect.size() / 2;
			double result = (double)(tempVect[index1] + tempVect[index2]) / 2;
			return result;
		}
	}
};

int main()
{
	Solution s1;
	vector<int> ip1{1,2};
	vector<int> ip2{3,4};

	//cout << s1.findMedianSortedArrays(ip1, ip2);
	printf("%.1f",s1.findMedianSortedArrays(ip1,ip2));

	return 0;
}