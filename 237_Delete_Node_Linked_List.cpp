/*Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.*/

void deleteNode(ListNode* node)
{
	ListNode* nextNode = node->next;
	node->val = nextNode->val;
	node->next = nextNode->next;
	delete nextNode;
}