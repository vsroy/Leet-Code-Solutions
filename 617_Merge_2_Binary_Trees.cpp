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

/*Function to merge 2 trees*/
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
	if (t1 == NULL)
		return t2;
	if (t2 == NULL)
		return t1;
	t1->val += t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;
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

	TreeNode* head1 = NULL;
	head1 = InsertNode(head, 4);
	head1 = InsertNode(head, 1);
	head1 = InsertNode(head, 7);
	head1 = InsertNode(head, 3);
	head1 = InsertNode(head, 2);
	head1 = InsertNode(head, 6);

	TreeNode* mergedHead = mergeTrees(head, head1);
	PrintInOrder(mergedHead);
	return 0;
}