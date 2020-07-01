/*Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.*/

#include<iostream>
#include<algorithm>
using namespace std;


// Definition for a binary tree node.
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

	int PathHelper(TreeNode* root, int& result)
	{
		if (root == NULL)
			return 0;
		
		int left = PathHelper(root->left,result);
		int right = PathHelper(root->right, result);

		/*Max path for parent call of root that includes atleast one child of root*/
		int left_Or_Right = max(max(left, right) + root->val, root->val);

		/*This assumes that there are no ancestors of the root*/
		int max_top = max(left_Or_Right, root->val + left + right);

		result = max(result, max_top);

		return left_Or_Right;
	}

	int maxPathSum(TreeNode* root) 
	{
		int result = INT_MIN;
		PathHelper(root,result);
		return result;
	}
};

int main()
{

}