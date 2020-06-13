/*Given a binary tree, return the zigzag level order traversal of its nodes' 
values. (ie, from left to right, then right to left for the next level and alternate between).*/

#include<iostream>
#include<queue>
#include<vector>
#include<queue>
using namespace std;

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

void mkvctr(queue<TreeNode *> &q, vector<vector<int>> &res, int c)
{
	while (!q.empty())
	{
		int s = q.size();
		vector<int> v;
		while (s--)
		{
			// struct TreeNode* rt = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
			v.push_back(q.front()->val);

			if (q.front()->left)  q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}

		if (c % 2 == 1)
		{
			reverse(v.begin(), v.end());
		}
		c++;

		res.push_back(v);
	}
	return;
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	if (!root) return{};
	vector<vector<int>> res;
	queue<TreeNode *> q;
	q.push(root);
	mkvctr(q, res, 2);
	return res;
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 3);
	head = InsertNode(head, 9);
	head = InsertNode(head, 20);
	head = InsertNode(head, 15);
	head = InsertNode(head, 7);

	std::vector<std::vector<int>> result = zigzagLevelOrder(head);

	for (auto i : result)
	{
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}