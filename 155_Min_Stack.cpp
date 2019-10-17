#include<iostream>
#include<vector>

class MinStack {
	std::vector<int> sampleVect;
	int minElement = INT_MAX;
public:
	/** initialize your data structure here. */
	MinStack() 
	{
	}

	void push(int x) 
	{
		if (x < minElement)
			minElement = x;
		sampleVect.push_back(x);
	}

	void pop() 
	{
		if (sampleVect.back() == minElement)
		{
			sampleVect.pop_back();
			minElement = INT_MAX;
			std::vector<int>::iterator it;
			for (it = sampleVect.begin(); it != sampleVect.end(); it++)
				if (*it < minElement)
					minElement = *it;
		}
		else
			sampleVect.pop_back();
	}

	int top() 
	{
		//std::cout << sampleVect.back() << std::endl;
		return sampleVect.back();
	}

	int getMin() 
	{
		//std::cout << minElement << std::endl;
		return minElement;
	}
};


int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();
	minStack.pop();
	minStack.top();   
	minStack.getMin();
	return 0;
}


