/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.*/

#include<iostream>
#include<map>

class Solution {
public:
	map<Node*, Node*>m;
	Node* copyRandomList(Node* head) {
		if (!head)
			return NULL;
		if (m.find(head) != m.end())
			return m[head];
		Node* newhead = new Node(head->val);
		m[head] = newhead;
		newhead->next = copyRandomList(head->next);
		newhead->random = copyRandomList(head->random);
		return newhead;
	}
};