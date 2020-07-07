/*Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time.
Each transformed word must exist in the word list.*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution 
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
	{
		/*Creating a set where we will store our words so that we can delete later on*/
		unordered_set<string> storageSet(wordList.begin(),wordList.end());

		/*The target word should be present in the array. If not, then return 0*/
		if (storageSet.find(endWord) == storageSet.end())
			return 0;

		queue<string> storageQueue;

		/*Inserting the starting word into the queue*/
		storageQueue.push(beginWord);

		/*Removing the starting word as we do not want loops*/
		storageSet.erase(beginWord);

		int result = 0;

		while (!storageQueue.empty())
		{
			int s = storageQueue.size();
			result++;

			/*Looping through all the items in the queue*/
			for (int i = 0; i < s; i++)
			{
				string currentWord = storageQueue.front();
				storageQueue.pop();
				
				if (currentWord == endWord)
					return result;	/*We have our target*/

				/*Looping through all the letters in the word*/
				for (int j = 0; j < currentWord.size(); ++j)
				{
					string temp = currentWord;

					/*For every letter, check if a new word can be formed(and if present in the set) by 
					replacing the letter with any of the 26 letters of the alphabet.*/
					for (int k = 0; k < 26; k++)
					{
						temp[j] = 'a' + k;

						/*If we find a match in the set replacing the current letter*/
						if (storageSet.find(temp) != storageSet.end())
						{
							/*Remove the element from the set and push the element into the queue*/
							storageSet.erase(temp);
							storageQueue.push(temp);
						}
					}
				}
			}
		}
		return 0;
	}
};

int main()
{
	Solution s1;
	vector<string> ipVect{ "hot", "dot", "dog", "lot", "log" };
	std::cout << s1.ladderLength("hit","cog",ipVect);
	return 0;
}