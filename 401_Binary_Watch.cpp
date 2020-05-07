/*Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times a binary watch could represent.*/

#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;


class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> res;
		for (int h = 0; h<12; h++) {
			for (int m = 0; m<60; m++) {
				if (bitset<10>(h << 6 | m).count() == num) { // rightmost 6 bits for minutes and left bits for hour.
					res.push_back(to_string(h) + (m<10 ? ":0" : ":") + to_string(m));
				}
			}
		}
		return res;
	}
};


int main()
{
	Solution s1;
	std::vector<std::string> vectTime = s1.readBinaryWatch(1);
	//Now print the array
	for (int i = 0; i < vectTime.size(); i++)
		std::cout << vectTime[i];
	return 0;
}