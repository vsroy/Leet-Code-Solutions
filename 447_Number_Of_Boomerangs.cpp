/*Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the 
distance between i and j equals the distance between i and k (the order of the tuple matters).
Find the number of boomerangs. You may assume that n will be at most 500 and coordinates 
of points are all in the range [-10000, 10000] (inclusive).*/

#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int count = 0;

		auto dist = [](vector<int>& a, vector<int>& b) {
			return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
		};

		for (int i = 0; i < points.size(); ++i) {
			unordered_map<int, int> distToPts;
			for (int j = 0; j < points.size(); ++j)
				if (i != j)
					distToPts[dist(points[i], points[j])]++;
			for (auto& it : distToPts)
				count += it.second * (it.second - 1);
		}

		return count;
	}
};

int main()
{
	std::vector<std::vector<int>> points = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
	Solution s1;
	std::cout << s1.numberOfBoomerangs(points);
	return 0;
}