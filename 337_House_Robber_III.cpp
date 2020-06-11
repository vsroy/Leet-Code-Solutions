/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this 
place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.*/

#include<iostream>
#include<algorithm>

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

int getans(TreeNode* root){
	if (root == NULL){
		return 0;
	}
	if (root->left == NULL && root->right == NULL){
		return root->val;
	}
	int option1 = root->val;
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	if (root->left != NULL && root->left->left != NULL){
		ans1 = getans(root->left->left);
	}
	if (root->left != NULL && root->left->right != NULL){
		ans2 = getans(root->left->right);
	}
	if (root->right != NULL && root->right->left != NULL){
		ans3 = getans(root->right->left);
	}
	if (root->right != NULL && root->right->right != NULL){
		ans4 = getans(root->right->right);
	}
	option1 += ans1 + ans2 + ans3 + ans4;
	int option2 = 0, option3 = 0;
	if (root->left != NULL){
		option2 = getans(root->left);
	}
	if (root->right != NULL){
		option3 = getans(root->right);
	}
	return std::max(option1, option2 + option3);
}

int rob(TreeNode* root)
{
	return getans(root);
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

	std::cout << rob(head);

	return 0;
}