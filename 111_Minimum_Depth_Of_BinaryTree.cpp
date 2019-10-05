#include<iostream>
#include<algorithm>
#include<math.h>

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

/*Function to return the minimum depth of a Binary Tree*/
int minDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else if (root->left == NULL && root->right != NULL)
		return minDepth(root->right) + 1;
	else if (root->left != NULL && root->right == NULL)
		return minDepth(root->left) + 1;
	else
		return (1 + std::min(minDepth(root->left), minDepth(root->right)));
}

int main()
{
	TreeNode* root = NULL;
	root = InsertNode(root, 1);
	root = InsertNode(root, 2);
	root = InsertNode(root, 3);
	root = InsertNode(root, 4);
	root = InsertNode(root, 5);
	root = InsertNode(root, 6);

	std::cout << minDepth(root);

	return 0;
}