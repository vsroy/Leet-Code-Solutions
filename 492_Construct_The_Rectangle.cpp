/*For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, 
your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
1. The area of the rectangular web page you designed must equal to the given target area.
2. The width W should not be larger than the length L, which means L >= W.
3. The difference between length L and width W should be as small as possible.
You need to output the length L and the width W of the web page you designed in sequence.*/

#include<iostream>
#include<vector>

class Solution 
{
public:
	std::vector<int> constructRectangle(int area) 
	{
		int diff = INT_MAX;
		int length = 0, width = 0;
		for (int i = 1; i <= sqrt(area); i++)
		{
			if (area % i == 0)
			{
				int local_width = area / i;
				if (abs(i - local_width) < diff)
				{
					if (i > local_width)
					{
						length = i;
						width = local_width;
					}
					else
					{
						width = i;
						length = local_width;
					}
				}
			}
		}
		std::vector<int> dimensionVector{ length, width };
		return dimensionVector;
	}
};

int main()
{
	Solution s1;
	std::vector<int> dimensionVect = s1.constructRectangle(4);
	return 0;
}