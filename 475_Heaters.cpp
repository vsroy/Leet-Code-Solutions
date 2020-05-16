/*Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that 
all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.*/

#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int ans = INT_MIN;
		sort(heaters.begin(), heaters.end());
		vector<int>::iterator it;
		for (int i : houses){
			it = lower_bound(heaters.begin(), heaters.end(), i);
			if (it == heaters.begin()) ans = max(ans, *it - i);
			else if (it == heaters.end()) ans = max(ans, i - *(it - 1));
			else ans = max(ans, min(i - *(it - 1), *it - i));
		}
		return ans;
	}
};


int main()
{
	Solution s1;
	std::vector<int> houses{ 1, 2, 3 ,4};
	std::vector<int> heaters{ 1,4 };
	std::cout << s1.findRadius(houses, heaters);
	return 0;
}