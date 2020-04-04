#include<iostream>
#include<stack>
class MyQueue
{
private:
	std::stack<int> pushStack;
	std::stack<int> popStack;

public:
	void push(int item);
	int pop();
	int peek();
	bool empty();
};

void MyQueue::push(int item)
{
	pushStack.push(item);
}

int MyQueue::pop()
{
	int poppedElement;
	if (popStack.empty())
	{
		while (!pushStack.empty())
		{
			popStack.push(pushStack.top());
			pushStack.pop();
		}
		poppedElement = popStack.top();
		popStack.pop();
	}
	else
	{
		poppedElement = popStack.top();
		popStack.pop();
	}
	return poppedElement;
}

/*Returns the element from the front of the queue*/
int MyQueue::peek()
{
	if (popStack.empty())
	{
		while (!pushStack.empty())
		{
			popStack.push(pushStack.top());
			pushStack.pop();
		}
		return popStack.top();
	}
	else
		return popStack.top();
}

bool MyQueue::empty()
{
	if (pushStack.empty() && popStack.empty())
		return true;
	else
		return false;
}

int main()
{
	MyQueue queue;

	queue.push(1);
	queue.push(2);
	std::cout << queue.peek() << std::endl;  // returns 1
	std::cout << queue.pop();   // returns 1
	std::cout << queue.empty(); // returns false
	return 0;
}