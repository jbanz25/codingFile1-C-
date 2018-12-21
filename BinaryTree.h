/**
* Jacob Bananal
*
* Chapter 21 - Homework 21 Programming Assignment
*
* May 22, 2018
*
**/

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
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
	int maxTreeWidth(BinaryTreeNode *);
	int treeWidth(BinaryTreeNode *, int);
public:
	//constructor 
	BinaryTree()
	{
		root = nullptr;
	}

	//Destructor
	~BinaryTree()
	{
		destroySubTree(root);
	}

	void insertBinaryNode(int);
	void displayInOrder() const
	{
		displayInOrder(root); //calls private member function 
	}
	int displayLeafCounter()
	{
		return leafCounter(root); //calls private member function
	}
	int displayTreeHeight()
	{
		return treeHeight(root); //calls private member function 
	}
	int displayTreeWidth()
	{
		return maxTreeWidth(root); // calls private member function 
	}
};

#endif //!BINARYTREE_H

