/**
* Jacob Bananal
*
* Chapter 21 - Homework 21 Programming Assignment
*
* May 22, 2018
*
**/

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private: 
	struct BinaryTreeNode
	{
		int value; // value in the node
		BinaryTreeNode *left; // pointer to the left child node 
		BinaryTreeNode *right; // pointer to the right child node 
	};

	BinaryTreeNode *root; //pointer to the root node

	//private member functions
	void insert(BinaryTreeNode *&, BinaryTreeNode *&);
	void destroySubTree(BinaryTreeNode *); //destructor
	void displayInOrder(BinaryTreeNode *) const;
	int leafCounter(BinaryTreeNode *);
	int treeHeight(BinaryTreeNode *);
	int treeWidth(BinaryTreeNode *);

public:
	//constructor 
	IntBinaryTree()
	{
		root = nullptr;
	}

	//Destructor
	~IntBinaryTree()
	{
		destroySubTree(root);
	}

	void insertBinaryNode(int);
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	int displayLeafCounter()
	{
		int i = leafCounter(root);
		return i;
	}
	int displayTreeHeight()
	{
		int h = treeHeight(root);
		return h;
	}
	int displayTreeWidth()
	{
		int w = treeWidth(root);
		return w;
	}
};
#endif // !INTBINARYTREE_H

