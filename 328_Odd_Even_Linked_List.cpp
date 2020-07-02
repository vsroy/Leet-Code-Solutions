/*Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.*/

#include<iostream>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Method to insert an element into the list
ListNode* InsertNode(ListNode* head, int x)
{
	if (head == NULL)
		return new ListNode(x);

	ListNode* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	ListNode* temp2 = new ListNode(x);
	temp->next = temp2;
	return head;
}

//Method to print the contents of a list
void Print(ListNode* head)
{
	ListNode* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->val << " ";
		temp = temp->next;
	}
}

ListNode* oddEvenList(ListNode* head) 
{
	if (head == NULL)
		return NULL;

	if (head->next == NULL)
		return head;

	ListNode* headodd = head;
	ListNode* headeven = head->next;
	ListNode* tempodd = headodd;
	ListNode* tempeven = headeven;
	ListNode* temp = head->next->next;

	int i = 1;
	while (temp != NULL)
	{
		if (i % 2 == 1)
		{
			tempodd->next = temp;
			tempodd = tempodd->next;
		}
		else
		{
			tempeven->next = temp;
			tempeven = tempeven->next;
		}
		temp = temp->next;
		i++;
	}

	tempeven->next = NULL;
	tempodd->next = NULL;

	temp = headodd;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = headeven;

	return headodd;
}

int main()
{
	ListNode* head = NULL;

	/*
	head = InsertNode(head, 1);
	head = InsertNode(head, 2);
	head = InsertNode(head, 3);
	head = InsertNode(head, 4);
	head = InsertNode(head, 5);
	*/

	head = InsertNode(head, 1);
	head = InsertNode(head, 2);
	head = InsertNode(head, 3);
	head = InsertNode(head, 4);

	//Print(head);

	head = oddEvenList(head);

	Print(head);

	return 0;
}