#include<iostream>
#include<vector>
#include<string>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 class Solution
 {
 public:
	 void binaryTreePathsHelper(vector<string>& vect, TreeNode* root, string res)
	 {
		 res += to_string(root->val);

		 if (root->left == NULL && root->right == NULL)
		 {
			 vect.push_back(res);
			 return;
		 }

		 if (root->left != NULL)
			 binaryTreePathsHelper(vect, root->left, res + "->");

		 if (root->right != NULL)
			 binaryTreePathsHelper(vect, root->right, res + "->");
	 }

	 vector<string> binaryTreePaths(TreeNode* root)
	 {
		 vector<string> vect;
		 
		 if (!root)
			 return vect;

		 binaryTreePathsHelper(vect, root, "");
		 
		 return vect;
	 }
 };