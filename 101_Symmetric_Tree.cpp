/*Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :*/
#include<iostream>
#include<queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*Function to insert Nodes in the tree*/
TreeNode* InsertNode(TreeNode* head, int item)
{
	if (head == NULL)
		return new TreeNode(item);
	if (item < head->val)
		head->left = InsertNode(head->left, item);
	else if (item > head->val)
		head->right = InsertNode(head->right, item);
	return head;
}

/*Function to print elements of the tree in In-Order fashion*/
void PrintBSTInOrder(TreeNode* head)
{
	if (head == NULL)
		return;
	PrintBSTInOrder(head->left);
	std::cout << head->val << " ";
	PrintBSTInOrder(head->right);
}

bool isSymmetricUtility(TreeNode* root1, TreeNode* root2)
{
	if ((root1 == NULL) && (root2 == NULL))
		return true;
	if (root1 && root2 && (root1->val == root2->val))
		return (isSymmetricUtility(root1->left, root2->right)
			 &&(isSymmetricUtility(root1->right, root2->left)));
	return false;
}

/*Function to find whether the Binary tree is symmetric/not. Use a queue to store nodes including NULL*/
bool isSymmetric(TreeNode* root) 
{
	return isSymmetricUtility(root,root);
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 1);
	InsertNode(head, 2);
	InsertNode(head, 3);
	InsertNode(head, 4);
	InsertNode(head, 5);

	PrintBSTInOrder(head);

	std::cout << "The is the BST symetric ? " << isSymmetric(head);

	return 0;
}