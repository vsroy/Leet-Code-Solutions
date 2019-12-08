#include<iostream>

struct Node
{
	Node* left;
	Node* right;
	int data;
};

Node* NewNode(int data)
{
	Node* newNode = new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void InOrder(Node* root)
{
	if (root == NULL)
		return;
	else
	{
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
}

Node* invertTree(Node* root)
{
	/*
	if (root == NULL)
		return;
	else
	{
		Node* temp;
		mirror(root->left);
		mirror(root->right);

		//Now swap the left and right nodes
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	*/

	if (!root) return NULL;
	auto k = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(k);
	return root;
}

int main()
{
	struct Node *root = NewNode(1);
	root->left = NewNode(2);
	root->right = NewNode(3);
	root->left->left = NewNode(4);
	root->left->right = NewNode(5);

	/* Print inorder traversal of the input tree */
	std::cout << "Inorder traversal of the constructed"
		<< " tree is" << std::endl;
	InOrder(root);

	/* Convert tree to its mirror */
	Node* root2 = invertTree(root);

	/* Print inorder traversal of the mirror tree */
	std::cout << "\nInorder traversal of the mirror tree"
		<< " is \n";
	InOrder(root2);

	return 0;
}