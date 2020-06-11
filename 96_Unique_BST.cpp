/*Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?*/

#include<iostream>
#include<vector>

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

int numTrees(int n) 
{
	std::vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < n + 1; i++)
		for (int j = 1; j <= i; j++)
			dp[i] += (dp[j - 1] * dp[i - j]);
	return dp[n];
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

	std::cout << numTrees(3) << std::endl;

	return 0;
}