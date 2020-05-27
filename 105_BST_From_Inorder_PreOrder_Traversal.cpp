/*Given preorder and inorder traversal of a tree, construct the binary tree.*/
#include<vector>
#include<iostream>

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
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder, int start, int end) 
	{
		static int preIndex = 0;
		
		if (start > end)
			return NULL;

		/*The first node of preorder will be the root node*/
		TreeNode *node = new TreeNode(preorder[preIndex++]);

		/*This node has no children*/
		if (start == end)
			return NULL;

		/*Finding out the index of the node in inorder array*/
		int index = searchNode(inorder,start,end,node->val);

		node->left = buildTree(preorder, inorder,start,index-1);
		node->right = buildTree(preorder, inorder, index + 1, end);

		return node;
	}

	int searchNode(std::vector<int>& inorder, int start, int end, int nodeVal)
	{
		for (int i = start; i <= end; i++)
			if (inorder[i] == nodeVal)
				return i;
	}
};

int main()
{
	Solution s1;
	std::vector<int> preOrder{ 3, 9, 20, 15, 7 };
	std::vector<int> inOrder{ 9, 3, 15, 20, 7 };
	TreeNode* root = s1.buildTree(preOrder, inOrder,0,inOrder.size()-1);
	return 0;
}