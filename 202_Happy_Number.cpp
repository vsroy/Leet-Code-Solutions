#include<iostream>
#include<set>

bool isHappy(int n) 
{
	std::set<int> happySet;
	int total = 0;
	while (n != 1)
	{
		int total = 0;
		while ((n / 10) != 0)
		{
			int rem = n % 10;
			total += rem*rem;
			n /= 10;
		}
		total += n * n;
		n = total;
		if (happySet.find(n) != happySet.end())
			return false;
		else
			happySet.insert(n);
	}
	return true;
}


int main()
{
	std::cout << isHappy(20) << std::endl;
	return 0;
}