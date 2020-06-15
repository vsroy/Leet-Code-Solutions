/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/
#include<iostream>
#include<queue>
#include<functional>


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
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


class Solution 
{
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) 
	{
		/*Base Case*/
		if (lists.empty())
			return NULL;

		std::priority_queue<int,std::vector<int>, std::greater<int>> listQueue;
		ListNode* temp = NULL;
		while(!(lists.empty()))
		{
			temp = lists.back();
			while (temp)
			{
				listQueue.push(temp->val);
				temp = temp->next;
			}
			lists.pop_back();
		}

		if (listQueue.empty())
			return NULL;

		ListNode* temp1 = NULL;
		temp1 = InsertNode(temp1,listQueue.top());
		
		listQueue.pop();
		ListNode* temp2 = temp1;
		//temp2 = temp2->next;
		while (!listQueue.empty())
		{
			temp2 = InsertNode(temp2,listQueue.top());
			listQueue.pop();
			//temp2 = temp2->next;
		}
		return temp1;
	}
};

void Print(ListNode* head)
{
	ListNode* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->val << " ";
		temp = temp->next;
	}
}


int main()
{

	ListNode* head = NULL;
	head = InsertNode(head, 1);
	head = InsertNode(head, 4);
	head = InsertNode(head, 5);
	

	ListNode* head2 = NULL;
	head2 = InsertNode(head2, 1);
	head2 = InsertNode(head2, 3);
	head2 = InsertNode(head2, 4);

	ListNode* head3 = NULL;
	head3 = InsertNode(head3, 2);
	head3 = InsertNode(head3, 6);

	Solution s1;

	std::vector<ListNode*> listVect;
	listVect.push_back(head);
	listVect.push_back(head2);
	listVect.push_back(head3);

	ListNode* mergedList = s1.mergeKLists(listVect);

	Print(mergedList);
	return 0;
}