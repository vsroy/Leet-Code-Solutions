/*Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.*/

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution 
{
public:
	int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) 
	{
		std::unordered_map<int, int> combiMap;
		
		for (auto i : A)
			for (auto j : B)
				
	}
};

int main()
{

	return 0;
}