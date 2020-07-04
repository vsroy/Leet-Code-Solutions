/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.*/
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:

	void PrintMatrix(std::vector<std::vector<int>>& matrix)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
				std::cout << matrix[i][j];
			std::cout << std::endl;
		}
	}

	void setZeroes(vector<vector<int>>& matrix) {
		int firstRow = -1;
		int firstColumn = -1;
		for (int i = 0; i<matrix.size(); i++){
			for (int j = 0; j<matrix[0].size(); j++){
				//cout<<"["<<i<<"]"<<"["<<j<<"]"<<endl;
				if (matrix[i][j] == 0 && i == 0){
					firstRow = 1;
				}
				if (matrix[i][j] == 0 && j == 0){
					firstColumn = 1;
				}
				if (matrix[i][j] == 0){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i<matrix.size(); i++){
			if (matrix[i][0] == 0){
				for (int j = 0; j<matrix[0].size(); j++){
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 1; i<matrix[0].size(); i++){
			if (matrix[0][i] == 0){
				for (int j = 1; j<matrix.size(); j++){
					matrix[j][i] = 0;
				}
			}
		}
		if (firstRow == 1){
			for (int i = 0; i<matrix[0].size(); i++){
				matrix[0][i] = 0;
			}
		}
		if (firstColumn == 1){
			for (int i = 0; i<matrix.size(); i++){
				matrix[i][0] = 0;
			}
		}

	}
};

int main()
{
	Solution s1;
	std::vector<std::vector<int>> matrix = {
		{ 1,1,1 },
		{ 1,0,1 },
		{ 1,1,1 },
	};
	s1.setZeroes(matrix);
	return 0;
}