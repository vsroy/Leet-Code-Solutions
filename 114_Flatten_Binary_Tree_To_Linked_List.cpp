/*Given a binary tree, flatten it to a linked list in-place.*/

/*Given two binary trees and imagine that when you put one of them to cover the other,
some nodes of the two trees are overlapped while the others are not.*/

#include<iostream>

struct TreeNode
{
	int val;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

/*Function to print the in-order(sorted) representation of the tree*/
void PrintInOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	PrintInOrder(root->left);
	std::cout << root->val << " ";
	PrintInOrder(root->right);
}

/*Function to insert a node into a tree*/
TreeNode* InsertNode(TreeNode*	head, int x)
{
	/*Creating a new treenode using the constructor*/
	if (head == NULL)
		return new TreeNode(x);
	if (x <= head->val)
		head->left = InsertNode(head->left, x);
	else
		head->right = InsertNode(head->right, x);
	return head;
}

void flatten(TreeNode* root) 
{
	/*Base condition - if root is null or if it is a leaf node*/
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;

	if (root->left != NULL)
	{
		/*Recur for left subtree*/
		flatten(root->left);
		TreeNode* temp = root->right;
		root->right = root->left;
		root->left = NULL;
		
		TreeNode* curr = root->right;
		while (curr->right != NULL)
			curr = curr->right;
		curr->right = temp;
	}
	flatten(root->right);
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 1);
	head = InsertNode(head, 2);
	head = InsertNode(head, 3);
	head = InsertNode(head, 4);
	head = InsertNode(head, 5);
	head = InsertNode(head, 5);

	PrintInOrder(head);
	std::cout << std::endl;
	flatten(head);

	PrintInOrder(head);

	return 0;
}