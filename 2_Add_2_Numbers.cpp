/*Leet Code : Problem Number 2*/
#include<iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

/*Function to create a new node and return the same*/
Node* NewNode(int val)
{
	Node* temp = new Node;
	temp->value = val;
	temp->next = NULL;
	return temp;
}

/*Function to insert a node in the Linked List*/
void Insert(Node** head, int item)	/*Double pointer to the head*/
{
	Node* temp = NewNode(item);

	temp->next = *head;
	*head = temp;
}

/*Function to print the contents of the list from head to tail*/
void PrintList(Node* head)
{
	if (head == NULL)
	{
		cout << "List is empty. Nothing to print\n";
		return;
	}
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node* head1 = NULL;
	Insert(&head1, 1);
	Insert(&head1, 2);
	Insert(&head1, 3);
	Insert(&head1, 4);
	Insert(&head1, 5);

	PrintList(head1);

	PrintList(head1);

	return 0;
}