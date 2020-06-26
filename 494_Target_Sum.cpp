/*You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int dp[25][2005];
	int helper(vector<int>&A, int curr, int index, int target)
	{
		if (curr == target && index == A.size()) return 1;
		if (index == A.size()) return 0;
		if (dp[index][curr + 1001] != -1) return dp[index][curr + 1001]; // sum might become negative

		int plus = helper(A, curr + A[index], index + 1, target);
		int minus = helper(A, curr - A[index], index + 1, target);
		dp[index][curr + 1001] = plus + minus;
		return plus + minus;
	}
	int findTargetSumWays(vector<int>& A, int s) {
		int len = A.size(), i;
		memset(dp, -1, sizeof(dp));
		return helper(A, 0, 0, s);
	}
};

int main()
{
	return 0;
}