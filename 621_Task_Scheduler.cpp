/*Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. 
Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals 
that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int leastInterval(std::vector<char>& tasks, int n) 
	{
		//int taskArray[26] = { 0 };
		std::vector<int> taskArray(26,0);

		/*Filling up the array with the frequency of each letter*/
		for (char taskID : tasks)
		{
			int temp = int(taskID) - 65;
			taskArray[temp] = taskArray[temp] + 1;
		}

		for (auto i : taskArray)
			std::cout << i << " ";
		std::cout << std::endl;

		/*Sorting the array based on increasing order of frequency*/
		std::sort(taskArray.begin(), taskArray.end());

		for (auto i : taskArray)
			std::cout << i << " ";
		std::cout << std::endl;

		int time = 0;	//Initialiaing the time which will be returned at the end

		while (taskArray[25] > 0)	//While there are items in the array to schedule where item at the last will have max frequency
		{
			int i = 0;
			while (i <= n)	/*We will add similar tasks until we reach the cooling period. 'i' is a variable that will store the cooling period*/
			{
				if (taskArray[25] == 0)	/*If there are no tasks at the end, we will break*/
					break;
				
				if (i < 26 && taskArray[25 - i]>0)	/*Make sure that we have not come full circle. Give a chance for each alphabet in every loop*/
					taskArray[25 - i]--;

				i++;
				time++;
			}
			std::sort(taskArray.begin(), taskArray.end());	/*After every iteration, we sort the array to put the next high frequency character at the end*/
		}
		return time;
	}
};

int main()
{
	Solution s1;
	std::vector<char> ipVect{'A','A','A','B','B','B'};
	std::cout << s1.leastInterval(ipVect,2);
	return 0;
}