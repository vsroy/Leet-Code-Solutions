/*Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.*/

#include<iostream>
#include<queue>
#include<functional>

class MedianFinder 
{

	/*Heap that will store elements in decreasing order*/
	std::priority_queue<double, std::vector<double>, std::greater<double>> small_heap;

	/*Heap that will store elements in increasing order*/
	std::priority_queue<double, std::vector<double>, std::less<double>> big_heap;

public:
	/** initialize your data structure here. */
	MedianFinder() 
	{

	}

	void addNum(int num)
	{
		if (big_heap.empty())
			big_heap.push(num);

		if (big_heap.size() == small_heap.size())
		{
			if (num >= big_heap.top())
				small_heap.push(num);
			else
				big_heap.push(num);
		}

		if (big_heap.size() > small_heap.size())
		{
			if (num >= big_heap.top())
				small_heap.push(num);
			else
			{
				small_heap.push(big_heap.top());
				big_heap.pop();
				big_heap.push(num);
			}
		}
		if (big_heap.size() < small_heap.size())
		{
			if (num < big_heap.top())
				big_heap.push(num);
			else
			{
				big_heap.push(small_heap.top());
				small_heap.pop();
				small_heap.push(num);
			}
		}
	}

	double findMedian() 
	{
		double median = 0;
		if (small_heap.size() == big_heap.size())
			return ((small_heap.top() + big_heap.top()) / 2);
		else if (small_heap.size() > big_heap.size())
			return small_heap.top();
		else
			return big_heap.top();
	}
};

int main()
{
	MedianFinder m1;
	m1.addNum(1);
	m1.addNum(2);
	std::cout << m1.findMedian();
	m1.addNum(3);
	std::cout << m1.findMedian();
	return 0;
}