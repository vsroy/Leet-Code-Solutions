/*Given a linked list, remove the n-th node from the end of list and return its head.*/

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

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* slow = head;
	ListNode* fast = head;

	int runner = 1;
	
	if (head == NULL)
		return NULL;

	if (head->next == NULL)
		return NULL;

	/*Keep fast pointer moving till nth position from the start of the list*/
	while (runner <= n && fast != NULL)
	{
		fast = fast->next;
		runner++;
	}

	/*n is longer than the length of the list*/
	if (runner < n)
		return NULL;
	/*If there is only one element in the list*/
	/*
	if ((runner - 1) == 1 && runner > n)
		return NULL;
		*/

	/*Move fast till we encounter the end of the list. The slow pointer will be at nth node from the list*/
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	/*If we have to delete the last element from the list*/
	if (slow->next == NULL)
	{
		ListNode* lastDelete = head;
		while (lastDelete->next->next != NULL)
			lastDelete = lastDelete->next;
		ListNode* temp = lastDelete->next;
		lastDelete->next = NULL;
		delete temp;
	}
	else
	{
		ListNode* temp = slow->next;
		slow->val = temp->val;
		slow->next = temp->next;
		delete temp;
	}

	return head;
}

int main()
{
	ListNode* head1 = NULL;
	head1 = InsertNode(head1, 1);
	//head1 = InsertNode(head1, 2);

	std::cout << std::endl;

	ListNode* nthNode = removeNthFromEnd(head1,1);

	std::cout << std::endl;

	Print(head1);
	
	return 0;
}