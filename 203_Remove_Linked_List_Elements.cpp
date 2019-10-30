/*Remove all elements from a linked list of integers that have value val.*/
#include<iostream>


// Definition for singly-linked list.
 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 /*Function to insert elements in Linked List*/
 ListNode* InsertElements(ListNode* head, int val)
 {
	 if (head == NULL)
		 return new ListNode(val);
	 
	 ListNode* temp = new ListNode(val);
	 temp->next = head;
	 head = temp;
	 return head;
 }

 /*Function to print the elements of a Linked List*/
 void PrintListElements(ListNode* head)
 {
	 ListNode* temp = head;
	 while (temp != NULL)
	 {
		 std::cout << temp->val << " ";
		 temp = temp->next;
	 }
 }

 /*Function to remove all the elements of the Linked List that contains the value 'val' */
ListNode* removeElements(ListNode* head, int val) 
{
	if (head == NULL)
		return head;
	ListNode* temp = head;
	while (temp != NULL && temp->val == val)	/*Removing all the head elements matching the value if there are any*/
	{
		head = temp->next;
		delete temp;
		temp = head;
	}

	temp = head;
	while ((temp != NULL) && (temp->next != NULL))
	{
		if (temp->next->val == val)
		{
			ListNode* temp2 = temp->next;	//10 20 40
			temp->next = temp2->next;
			delete temp2;
		}
		else
			temp = temp->next;
	}
	return head;
}



int main()
{
	ListNode* head = NULL;
	head = InsertElements(head, 1);
	/*
	head = InsertElements(head, 1);
	head = InsertElements(head, 2);
	head = InsertElements(head, 6);
	head = InsertElements(head, 3);
	head = InsertElements(head, 4);
	head = InsertElements(head, 5);
	head = InsertElements(head, 6);
	*/
	PrintListElements(head);
	head = removeElements(head, 1);
	std::cout << std::endl;
	PrintListElements(head);
	return 0;
}