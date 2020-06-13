/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored 
in a file or memory buffer, or transmitted across a 
network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization 
algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be 
deserialized to the original tree structure.*/

/*We will do a pre order traversal to navigate the tree for both serialization and de-serialization*/

#include<iostream>
#include<string>
#include<sstream>

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

void SerializeHeper(std::stringstream& ss, TreeNode* root)
{
	if (root == NULL)	//We have reached the left/right of a leaf node, we mark it using a special character
	{
		ss << "# ";
		return;
	}
	ss << root->val << " ";	//Use the string stream class to convert integer value to string
	SerializeHeper(ss, root->left);
	SerializeHeper(ss, root->right);
}

// Encodes a tree to a single string.
std::string serialize(TreeNode* root) 
{
	std::stringstream ss;
	SerializeHeper(ss, root);
	return ss.str();
}

void DeserializeHelper(TreeNode* root, std::stringstream& ss)
{
	std::string node;
	ss >> node;

	//If we get a value of '#' in the string, we just have to assign current value as NULL
	if (node == "" || node == "#")
	{
		root = NULL;
		return;
	}

	std::stringstream sss(node);
	int data;
	sss >> data;

	//Convert the string to integer val and then assign the int to the value of current node
	root = new TreeNode(data);
	root->left = root->right = NULL;

	//Recur for left and right subtrees following pre-order traversla
	DeserializeHelper(root->left, ss);
	DeserializeHelper(root->right, ss);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data) 
{
	std::stringstream ss(data);
	TreeNode* root = NULL;
	DeserializeHelper(root, ss);
	return root;
}

int main()
{
	TreeNode* head = NULL;
	head = InsertNode(head, 1);
	head = InsertNode(head, 2);
	head = InsertNode(head, 3);
	head = InsertNode(head, 4);
	head = InsertNode(head, 5);
	head = InsertNode(head, 5);

	return 0;
}