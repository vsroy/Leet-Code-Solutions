#include<iostream>
#include<vector>
#include<set>

class Solution {
public:

	std::vector<int> Utility(std::vector<int>& small, std::vector<int>& large)
	{
		std::vector<int> vectIntersect;
		std::vector<int>::iterator it;
		for (int i = 0; i < small.size(); i++)
		{
			int currNum = small[i];
			it = std::find(large.begin(), large.end(), currNum);
			if (it != large.end())
			{
				std::vector<int>::iterator it2;
				it2 = std::find(vectIntersect.begin(), vectIntersect.end(), currNum);
				if (it2 == vectIntersect.end())
					vectIntersect.push_back(currNum);
			}
		}
		return vectIntersect;
	}
	
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		if (nums1.size() > nums2.size())
			return Utility(nums2, nums1);
		else
			return Utility(nums1, nums2);
	}
};


int main()
{
	Solution s1;
	std::vector<int> vect1{ 4, 9, 5 };
	std::vector<int> vect2{9,4,9,8,4};
	std::vector<int> vectAns = s1.intersection(vect1,vect2);

	std::vector<int>::iterator it;
	for (it = vectAns.begin(); it != vectAns.end(); it++)
		std::cout << *it << " ";
	return 0;
}