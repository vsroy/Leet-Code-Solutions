
/*You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/

#include<iostream>
using namespace std;

// Definition for a Node.
class Node 
{
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};



class Solution 
{
public:

	Node* getNextRight(Node* node)
	{
		Node* temp = node->next;
		while (temp != NULL)
		{
			if (temp->left)
				return temp->left;
			if (temp->right)
				return temp->right;
			else
				temp = temp->next;
		}
		return NULL;
	}

	/*Iterative solution*/
	Node* connect(Node* temp)
	{
		/*Base case if root is NULL*/
		Node* root = temp;
		if (!root)
			return NULL;

		/*Set next right of root as NULL*/
		root->next = NULL;
		while (root)
		{
			Node* q = root;

			/*Connect all nodes at the same level as the children nodes of root*/
			while (!q)
			{
				/*Check for letf node of current Node*/
				if (q->left)
				{
					if (q->right)
						q->left->next = q->right;
					else
						q->left->next = getNextRight(q);
				}
				
				/*Check for the right node of q*/
				if (q->right)
					q->right->next = getNextRight(q);

				/*Do the same for all the remaining nodes at the same level*/
				q = q->next;
			}

			/*Start from the first node at the next level*/
			if (root->left != NULL)
				root = root->left;
			if (root->right != NULL)
				root = root->right;
			else
				root = getNextRight(root);
		}
		return temp;
	}
};

/*Alternative solution*/
Node* connectRight(Node* root) 
{
	Node *pre = root, *cur;
	while (pre) {
		cur = pre;
		while (cur && cur->left) {
			cur->left->next = cur->right;
			if (cur->next) {
				cur->right->next = cur->next->left;
			}
			cur = cur->next;
		}
		pre = pre->left;
	}
	return root;
}

int main()
{
	return 0;
}