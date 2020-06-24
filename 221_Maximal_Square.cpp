/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int M = matrix.size(); if (M == 0) return 0;
		int N = matrix[0].size();

		vector<vector<int>> DP(M + 1, vector<int>(N + 1, 0));
		int largest = 0;
		for (int i = 1; i<M + 1; i++) {
			for (int j = 1; j<N + 1; j++) {
				if (matrix[i - 1][j - 1] == '1') {
					DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
					largest = max(DP[i][j], largest);
				}
			}
		}
		return largest*largest;
	}
};


int main()
{
	Solution s1;
	std::vector<std::vector<char>> matrix{
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' },
	};

	std::cout << s1.maximalSquare(matrix);
	return 0;
}