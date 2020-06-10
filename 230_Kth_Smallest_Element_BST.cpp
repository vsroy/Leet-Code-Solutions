/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.*/

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

/*Perform in-order traversal*/
TreeNode* kthSmallestUtility(TreeNode* root,int& count, int k)
{
	/* This is also a solution but this will traverse every tree even if condition is met
	if (root == NULL)
		return;
	kthSmallestUtility(root->left, count, k, answer);
	count++;
	
	if (count == k)
		answer = root->val;

	kthSmallestUtility(root->right, count, k, answer);
	*/

	if (root == NULL)
		return NULL;

	//Search in the left subtree
	TreeNode* left = kthSmallestUtility(root->left, count, k);

	/*If kth smallest element is found in the left subtree*/
	if (left != NULL)
		return left;

	count++;

	//If we find the kth smallest element, we return the TreeNode
	if (count == k)
		return root;


	return kthSmallestUtility(root->right, count, k);
}

int kthSmallest(TreeNode* root, int k) 
{
	int count = 0;
	TreeNode* answer = kthSmallestUtility(root, count, k);
	return answer->val;
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 3);
	head = InsertNode(head, 1);
	head = InsertNode(head, 5);
	head = InsertNode(head, 2);

	PrintInOrder(head);

	std::cout << std::endl << kthSmallest(head,4);

	return 0;
}
