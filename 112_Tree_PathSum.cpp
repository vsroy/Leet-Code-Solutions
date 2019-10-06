#include<iostream>

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

/*Function to find whether there is path from root to any leaf with sum adding up to passed sum argument*/
bool hasPathSum(TreeNode* root, int sum) 
{
	if (root == NULL)
		return false;
	else if ((root->val == sum) && (root->left == NULL) && (root->right == NULL))
		return true;
	else
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main()
{
	TreeNode* root = NULL;
	InsertNode(root, 1);
	InsertNode(root, 2);
	InsertNode(root, 3);
	InsertNode(root, 4);
	InsertNode(root, 5);
	std::cout << hasPathSum(root, 15);
	return 0;
}