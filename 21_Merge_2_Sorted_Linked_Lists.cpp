/*Merge two sorted linked lists and return it as a new sorted list. The new list should be made by 
splicing together the nodes of the first two lists.*/

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

/*
class Solution 
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{

	}
};
*/


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL && l2 == NULL)
		return NULL;
	if (l1 == NULL && l2 != NULL)
		return l2;
	if (l1 != NULL && l2 == NULL)
		return l1;

	ListNode* head1 = l1;
	ListNode* head2 = l2;

	ListNode* runner;
	
	/*Initializing the runner to the head of the first or second list whichever is smaller*/
	if (head1->val < head2->val)
	{
		runner = head1;
		head1 = head1->next;
	}
	else
	{
		runner = head2;
		head2 = head2->next;
	}

	/*Assign a temp node to runner which we will be returning later*/
	ListNode* temp = runner;


	while (head1 != NULL && head2 != NULL)
	{
		if (head1->val < head2->val)
		{
			runner->next = head1;
			head1 = head1->next;
			runner = runner->next;
		}
		else
		{
			runner->next = head2;
			head2 = head2->next;
			runner = runner->next;
		}
	}

	if (head1 == NULL)
	{
		while (head2 != NULL)
		{
			runner->next = head2;
			head2 = head2->next;
			runner = runner->next;
		}
	}
	else if (head2 == NULL)
	{
		while (head1 != NULL)
		{
			runner->next = head1;
			head1 = head1->next;
			runner = runner->next;
		}
	}
	return temp;
}

int main()
{
	ListNode* head1 = NULL;
	head1 = InsertNode(head1, -9);
	head1 = InsertNode(head1, 3);
	Print(head1);

	std::cout << std::endl;

	ListNode* head2 = NULL;
	head2 = InsertNode(head2, 5);
	head2 = InsertNode(head2, 7);
	Print(head2);

	std::cout << std::endl;

	ListNode* runner = mergeTwoLists(head1,head2);

	Print(runner);
	
	std::cout << std::endl;

	return 0;
}