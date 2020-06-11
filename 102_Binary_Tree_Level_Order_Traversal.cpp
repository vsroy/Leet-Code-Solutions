/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).*/

#include<iostream>
#include<queue>
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

std::vector<std::vector<int>> levelOrder(TreeNode* root) 
{
	std::vector<std::vector<int>> resultVect;
	std::queue<TreeNode*> treeQueue;
	if (root == NULL)
		return resultVect;
	treeQueue.push(root);
	treeQueue.push(NULL);
	std::vector<int> localVect;

	while (!treeQueue.empty())
	{
		/*Condition to check the occurrence of next level*/
		if (treeQueue.front() == NULL)
		{
			resultVect.push_back(localVect);
			if (treeQueue.size() == 1)
				break;
			localVect.clear();
			treeQueue.push(NULL);
			treeQueue.pop();
		}
		else
		{
			TreeNode* front = treeQueue.front();
			localVect.push_back(front->val);
			treeQueue.pop();
			if (front->left != NULL)
				treeQueue.push(front->left);
			if (front->right != NULL)
				treeQueue.push(front->right);
			localVect.push_back(front->val);
		}
	}
	return resultVect;
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 3);
	head = InsertNode(head, 9);
	head = InsertNode(head, 20);
	head = InsertNode(head, 15);
	head = InsertNode(head, 7);

	std::vector<std::vector<int>> result = levelOrder(head);

	for (auto i : result)
	{
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}