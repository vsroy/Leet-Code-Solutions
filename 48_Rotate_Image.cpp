/*You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int N = matrix.size();

		/*Loop for the number of cycles*/
		for (int i = 0; i < N / 2; i++)
		{
			/*Loop for each element in the cycle*/
			for (int j = i; j < N - i - 1; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[N - 1 - j][i];
				matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
				matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
				matrix[j][N - 1 - i] = temp;
			}
		}
	}
};

int main()
{
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	Solution s1;
	s1.rotate(matrix);

	for (auto i : matrix)
	{
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}