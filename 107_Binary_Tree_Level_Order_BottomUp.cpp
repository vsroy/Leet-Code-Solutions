#include<iostream>
#include<queue>
#include<stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*Function to insert Nodes in the tree*/
TreeNode* InsertNode(TreeNode* head, int item)
{
	if (head == NULL)
		return new TreeNode(item);
	if (item < head->val)
		head->left = InsertNode(head->left, item);
	else if (item > head->val)
		head->right = InsertNode(head->right, item);
	return head;
}

/*Function to print elements of the tree in In-Order fashion*/
void PrintBSTInOrder(TreeNode* head)
{
	if (head == NULL)
		return;
	PrintBSTInOrder(head->left);
	std::cout << head->val << " ";
	PrintBSTInOrder(head->right);
}

std::vector<std::vector<int>> LevelOrderTraversalByLine(TreeNode* head)
{
	std::vector<std::vector<int>> vectTree;
	std::stack<std::vector<int>> stackTree;
	if (head == NULL)
	{
		std::cout << "Tree is empty";
		return vectTree;
	}
	std::queue<TreeNode*> TreeQueue;
	TreeQueue.push(head);
	std::vector<int> tempVector;

	while (!TreeQueue.empty())
	{
		int nodeCount = TreeQueue.size();
		while (nodeCount > 0)
		{
			TreeNode* temp = TreeQueue.front();
			if (temp->left != NULL)
				TreeQueue.push(temp->left);
			if (temp->right != NULL)
				TreeQueue.push(temp->right);
			std::cout << temp->val << " ";
			tempVector.push_back(temp->val);
			TreeQueue.pop();
			nodeCount--;
		}
		std::cout << std::endl;
		stackTree.push(tempVector);
		tempVector.clear();
	}
	while (!stackTree.empty())
	{
		vectTree.push_back(stackTree.top());
		stackTree.pop();
	}
	return vectTree;
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 4);
	InsertNode(head, 3);
	InsertNode(head, 5);
	InsertNode(head, 2);
	InsertNode(head, 6);
	//PrintBSTInOrder(head);
	std::vector<std::vector<int>> sampleVector = LevelOrderTraversalByLine(head);

	std::cout << "The vector after in-order reversal is \n";
	for (int i = 0; i < sampleVector.size(); i++)
	{
		std::vector<int> tempVector = sampleVector[i];
		for (int j = 0; j < tempVector.size(); j++)
			std::cout << tempVector[j] << " ";
		std::cout << std::endl;
	}

	return 0;
}