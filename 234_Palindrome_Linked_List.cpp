/*Given a singly linked list, determine if it is a palindrome.*/

#include<iostream>
#include<stack>

struct Node
{
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL){}
};

bool IsPalindrome(Node* head)
{
	std::stack<int> listStack;
	Node* temp = head;
	while (temp != NULL)
	{
		listStack.push(temp->val);
		temp = temp->next;
	}

	/*Now stack is filled with all list elements*/
	temp = head;

	while (!listStack.empty())
	{
		if (temp->val != listStack.top)
			return false;
		else
		{
			temp = temp->next;
			listStack.pop();
		}
	}
	return true;
}

int main()
{

}