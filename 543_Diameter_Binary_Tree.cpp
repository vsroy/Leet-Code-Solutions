/*Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the 
length of the longest path between any two nodes in a tree. This path may or may not pass through the root.*/

#include<iostream>
#include<algorithm>

 //Definition for a binary tree node.
 struct TreeNode {
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

	int answer = 0;

	int diameter(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int l = diameter(root->left);
		int r = diameter(root->right);

		answer = std::max(answer, l + r);
		return std::max(l, r) + 1;
	}
	
	int diameterOfBinaryTree(TreeNode* root) 
	{
		if (root == NULL)
			return 0;
		diameter(root);
		return answer;
	}
};