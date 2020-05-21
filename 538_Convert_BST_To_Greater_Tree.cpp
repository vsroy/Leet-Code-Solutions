/*Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.*/

#include<iostream>


//Definition for a binary tree node.
 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 

class Solution 
{
public:

	void Traverse(TreeNode* root)
	{
		if (root == NULL)
			return;
		else
		{
			Traverse(root->left);

			/*Find the greater value*/
			TreeNode* tempRoot = root;
			int totalSum = tempRoot->val;
			while (tempRoot->right != NULL)
			{
				totalSum = tempRoot->right->val;
				tempRoot = tempRoot->right;
			}
			root->val = totalSum;

			Traverse(root->right);
		}
	}

	TreeNode* convertBST(TreeNode* root) 
	{
		Traverse(root);
	}
};