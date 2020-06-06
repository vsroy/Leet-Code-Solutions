/*Sort a linked list in O(n log n) time using constant space complexity.*/

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

/*Function to check whether a linked list has a cycle*/
ListNode* HasCycle(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;

	if (head == NULL || head->next == NULL)
		return false;

	bool hasCycle = false;;

	/*This loop checks if there is a cycle in the linked list*/
	do
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			hasCycle = true;
	}
	while (fast != NULL && slow != NULL && fast->next != NULL)

	/*Assigning the slow pointer to head*/
	slow = head;

	/*Moving slow and fast pointer by one until they meet*/
	while (slow != fast && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
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


	
	return 0;
}