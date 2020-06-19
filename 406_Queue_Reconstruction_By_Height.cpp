/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater 
than or equal to h. Write an algorithm to reconstruct the queue.
*/

#include<iostream>
#include<vector>
#include<algorithm>


class Solution 
{
	static bool compare(std::vector<int> a, std::vector<int> b)
	{
		return (a[0] > b[0] || a[0] == b[0] && a[1] < b[1]);
	}


public:
	std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
	{
		/*Sorting the vector elements based on the function*/
		std::sort(people.begin(), people.end(), compare);

		std::vector<std::vector<int>> result;

		/*Looping through the sorted vectors one after the other and inserting them at the correct position
		estimating that lower height numbers will be placed at the front and will be replaced by numbers wtih shorter height*/
		for (std::vector<int> arr : people)
			result.insert(result.begin() + arr[1], arr);

		return result;
	}
};

int main()
{
	std::vector<std::vector<int>> ipVect;
	ipVect.push_back({7,0});
	ipVect.push_back({ 4, 4 });
	ipVect.push_back({ 7, 1 });
	ipVect.push_back({ 5, 0 });
	ipVect.push_back({ 6, 1 });
	ipVect.push_back({ 5, 2 });

	Solution s1;
	std::vector<std::vector<int>> resultVect = s1.reconstructQueue(ipVect);
	return 0;
}