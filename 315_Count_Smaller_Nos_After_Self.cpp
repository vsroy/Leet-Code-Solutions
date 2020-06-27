/*You are given an integer array nums and you have to return a new counts array. The counts array has the property 
where counts[i] is the number of smaller elements to the right of nums[i].*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(int value){
		val = value;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	map<Node*, int>smalls;
	void insert_into_BST(Node* &root, int val, int &c){
		if (root == NULL){
			Node* new_node = new Node(val);
			root = new_node;
			smalls[root] = 0;
		}
		else if (val <= root->val){
			smalls[root]++;
			insert_into_BST(root->left, val, c);
		}
		else if (val == root->val){
			c += smalls[root];
			insert_into_BST(root->left, val, c);
		}
		else{
			c += smalls[root] + 1;
			insert_into_BST(root->right, val, c);
		}
		return;
	}

	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int>counts(n, 0);
		Node* root = NULL;
		for (int i = n - 1; i >= 0; i--){
			int c = 0;
			insert_into_BST(root, nums[i], c);
			counts[i] = c;
		}
		return counts;
	}
};

int main()
{

}