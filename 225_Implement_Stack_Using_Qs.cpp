#include<queue>
#include<iostream>
class MyStack {
public:
	/** Initialize your data structure here. */
	std::queue<int> queue1;
	std::queue<int> queue2;
	MyStack() 
	{
		
	}

	/** Push element x onto stack. */
	void push(int x) 
	{
		if (!queue1.empty())
			queue1.push(x);
		else
			queue2.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() 
	{
		int poppedElement;
		if (!queue1.empty())
		{
			while (queue1.size() != 1)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			poppedElement = queue1.front();
			queue1.pop();
			return poppedElement;
		}
		else if (!queue2.empty())
		{
			while (queue2.size() != 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			poppedElement = queue2.front();
			queue2.pop();
			return poppedElement;
		}
		else
			return NULL;
	}

	/** Get the top element. */
	int top() 
	{
		if (!queue1.empty())
			return queue1.back();
		else if (!queue2.empty())
			return queue2.back();
		else
			return NULL;
	}

	/** Returns whether the stack is empty. */
	bool empty() 
	{
		if (queue1.empty() && queue2.empty())
			return true;
		else
			return false;
	}
};

int main()
{
	MyStack stack;

	stack.push(1);
	std::cout << stack.pop();   // returns 2
	std::cout << stack.empty(); // returns false
	return 0;
}
