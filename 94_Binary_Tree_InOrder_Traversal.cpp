/*Given a binary tree, return the inorder traversal of its nodes' values.*/


#include<iostream>
#include<vector>
#include<stack>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
	std::vector<int> inorderTraversal(TreeNode* root) 
	{
		std::vector<int> inOrderVect;
		std::stack<TreeNode*> binaryStack;
		if (root == NULL)
			return inOrderVect;

		TreeNode* current = root;

		while (current != NULL || !binaryStack.empty())
		{
			while (current != NULL)
			{
				binaryStack.push(current);
				current = current->left;
			}

			inOrderVect.push_back(binaryStack.top()->val);

			current = binaryStack.top();
			binaryStack.pop();

			current = current->right;
		}
		return inOrderVect;
	}
};