/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) 
	{
		/*Vector that will store that for a specific course, how many courses should be taken*/
		std::vector<int> degree(numCourses);

		/*Vector that reverses the prerequisites vector*/
		std::vector<std::vector<int>> reverse(numCourses);

		/*The final vector that will max number of courses that can be completed*/
		std::vector<int> bfs;

		for (int i = 0; i < prerequisites.size(); i++)
		{
			/*Looping through the prerequisites vector and storing how many courses are dependent on a specific course*/
			reverse[prerequisites[i][1]].push_back(prerequisites[i][0]);

			/*Storing how many courses are required to be completed for a particular course which is the degree of the course*/
			degree[prerequisites[i][0]]++;
		}

		/*For those courses which do not have dependency, we directly add it to the result*/
		for (int i = 0; i < numCourses; i++)
		{
			if (degree[i] == 0)
				bfs.push_back(i);
		}

		/*Looping through all elements in result set, picking the ones which do not have any dependency*/
		for (int i = 0; i < bfs.size(); i++)
		{
			/*Looping through the dependent courses(vector) of the current course which does not have any dependency*/
			for (int j = 0; j < reverse[bfs[i]].size(); j++)
			{
				if (--degree[reverse[bfs[i]][j]] == 0)
					bfs.push_back(reverse[bfs[i]][j]);
			}
		}
		return (bfs.size() == numCourses);
	}
};

int main()
{
	return 0;
}