/*Merge two sorted linked lists and return it as a new sorted list. The new list should be made by
splicing together the nodes of the first two lists.*/

#include<iostream>
#include<vector>

#include<algorithm>
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


ListNode* sortList(ListNode* head) 
{
	ListNode* temp = head;
	std::vector<int> listVect;
	while (temp != NULL)
	{
		listVect.push_back(temp->val);
		temp = temp->next;
	}

	std::sort(listVect.begin(),listVect.end());

	temp = head;
	std::vector<int>::iterator vectIter = listVect.begin();
	while (temp != NULL)
	{
		temp->val = *vectIter;
		vectIter++;
		temp = temp->next;
	}
	return head;
}

int main()
{
	ListNode* head1 = NULL;
	head1 = InsertNode(head1, -9);
	head1 = InsertNode(head1, 3);
	Print(head1);

	std::cout << std::endl;

	ListNode* head2 = NULL;
	head2 = InsertNode(head2, 4);
	head2 = InsertNode(head2, 2);
	head2 = InsertNode(head2, 1);
	head2 = InsertNode(head2, 3);
	Print(head2);
	std::cout << std::endl;
	ListNode* head3 = sortList(head2);
	Print(head3);
	std::cout << std::endl;

	return 0;
}