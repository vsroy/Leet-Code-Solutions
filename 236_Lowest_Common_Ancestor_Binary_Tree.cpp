/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.*/

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

TreeNode* LowestCommonAncestorUtility(TreeNode* root, int n1, int n2)
{
	if (root == NULL)
		return;

	/*If we find an exact match, return*/
	if (root->val == n1 || root->val == n2)
		return root;

	/*Checking the left of the subtree*/
	TreeNode* left = LowestCommonAncestorUtility(root->left,n1,n2);

	/*Checking the right of the subtree*/
	TreeNode* right = LowestCommonAncestorUtility(root->right, n1, n2);

	/*If we find that left and right are both not null, it means that left and right subtree contains values each, current node is the LCA*/
	if (left != NULL && right != NULL)
		return root;

	/*If we find both values in left and right subtree, we return that subtree*/
	if (left != NULL)
		return left;
	else
		return right;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	return LowestCommonAncestorUtility(root, p->val, q->val);
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

	std::cout << lowestCommonAncestor(head);

	return 0;
}