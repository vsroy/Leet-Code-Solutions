/*You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your 
secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate 
in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
Please note that both secret number and friend's guess may contain duplicate digits.*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

std::string getHint(std::string secret, std::string guess) 
{
	int bulls = 0;
	int cows = 0;
	std::vector<char> vectSecret;
	std::vector<char> vectGuess;

	/*Insert all the elements inside the vector*/
	for (int i = 0; i < secret.size(); i++)
	{
		vectGuess.push_back(guess[i]);
		vectSecret.push_back(secret[i]);
	}

	std::vector<char>::iterator iterSecret;
	/*Now iterate through all the elements in the guess vector*/
	std::vector<char>::iterator it = vectGuess.begin();
	for (int i = 0; i < vectGuess.size(); i++)
	{
		if (vectGuess[i] == vectSecret[i])
		{
			bulls++;
			vectSecret[i] = 'X';	/*Assuming there are no negative numbers in the game*/
			vectGuess[i] = 'O';
		}
	}
	for (int i = 0; i < vectGuess.size(); i++)
	{
		iterSecret = std::find(vectSecret.begin(), vectSecret.end(), vectGuess[i]);
		if (iterSecret != vectSecret.end())
		{
			cows++;
			*iterSecret = 'X';
		}
	}

	std::stringstream ss1;
	ss1 << bulls;
	
	std::stringstream ss2;
	ss2 << cows;

	return (ss1.str() + "A" + ss2.str() + "B");
}

int main()
{
	//std::cout << getHint("1807","7810");
	//std::cout << getHint("011", "110");
	std::cout << getHint("11", "10");
	return 0;
}