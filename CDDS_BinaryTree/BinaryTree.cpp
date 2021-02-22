#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int value)
{
	//If the tree is empty, set the root to be a new node with the given value.
	if (isEmpty())
	{
		m_root = new TreeNode(value);

	}

	TreeNode* current = m_root;

	TreeNode* parent;

	while(current != nullptr)
	{
		// IF the value is less than this piece of code is called
		if(value < current->getData())
		{
			// The parent is set to be the current
			parent = current;
			
			// Current is set to be the left of the parent 
			current = parent->getLeft();

			// If the parent's left is null a new node is made with the value and placed at the location
			if (parent->getLeft() == nullptr)
				current = new TreeNode(value);
		}

		// IF the value is More than this piece of code is called
		if (current->getData() < value)
		{
			// The parent is set to be the current
			parent = current;

			// Current is set to be the right of the parent 
			current = parent->getRight();

			// If the parent's right is null a new node is made with the value and placed at the location
			if (parent->getRight() == nullptr)
				current = new TreeNode(value);
		}

		if (current == current)
			return;

	}
		
}

void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove
	//and another to hold a reference to its parent.

	//Try to find the node that matches the value given and its parent in the tree.
	//If the node cannot be found return.


	//Check to see if the node has a right

		//Initialize two iterators to find the node whose data will be copied and its parent.

		//Set the first iterator to point to the right child of the node we want to remove.

		//Loop while the first iterator has a value to its left

			//Set the second iterator to be the value of the first iterator.
			//Set the first iterator to be the value to the left of it

		//end loop

		//Once the smallest value has been found, copy the data in first iterator to the node we want to remove.

		//Check if the second iterator has a left child.
			//Check if the left child stores the same data as the node we wanted to remove.
				//Set the second iterators left child to be the first iterators right child.

		//Check if the second iterator has a right child.
			//Check if the right child contains the same data as the node we want to remove.
				//Set the right child of the second iterator to be the right child of the first iterator.

		//Delete the first iterator

	//Otherwise, if the node doesn't have a right child

		//check if the parent of the node to remove has a left child.
			//Check if the data that the left child holds is the same as the data the node to remove holds.
				//Set the left child of the parent node to be the left child of the node to remove.

		//Check if the parent of the node to remove has a right child.
			//Check if the data the right child holds is the same as the data the node to remove holds.
				//Set the right child of the parent node to be the left child of the node to remove.

		//Check if the node we want to remove is the root.
			//Set the root to be its left child.

		//Delete the pointer that points to the node to remove.
}

TreeNode* BinaryTree::find(int value)
{
	//Initialize an iterator starting at the root.
	TreeNode* current = m_root;

	
	while(current != nullptr)
	{
		// If the value's data equal's the currents data then current is returned
		if (current->getData() == value) 
		{
			return current;
		}
		
		// If the value does not equal current and the data from current is more than the value
		else if (current->getData() != value && current->getData() > value)
		{
			// Current equals current's right child node
			current = current->getRight();
		}

		// If the value does not equal current and the data from current is less than the value
		else if (current->getData() != value && current->getData() < value)
		{
			// Current equals currents right child nod
			current = current->getRight();
		}
	}

	return nullptr;

}

void BinaryTree::draw(TreeNode* selected)
{
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	//and the other to hold a reference to the parent.

	TreeNode* parent;
	TreeNode* current = m_root;

	while (current != nullptr)
	{
		// If the searchValue equals current then this block is used
		if (searchValue == current->getData())
		{
			// The nodeFound is set to equal current
			nodeFound = current;

			// The parent node equals the parent node reference passed in the function then return true
			parent = nodeParent;
			return true;
		}

		// If the searchValue does not equal current and the data from current is more than the searchValue
		if (searchValue != current->getData() && searchValue < current->getData())
		{
			// The parent pointer is set to equal current
			parent = current;

			// Curremt is set to currents left child then loops the while loop
			current = current->getLeft();
		}

		// If the value does not equal current and the data from current is less than the value
		if (searchValue != current->getData() && searchValue > current->getData())
		{
			// The parent pointer is set to equal current
			parent = current;

			// Curremt is set to currents right child then loops the while loop
			current = current->getRight();
		}
	}

	return false;
	
}

void BinaryTree::draw(TreeNode* currentNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	if(currentNode)
	{
		// If the node has a left child this portion is called
		if (currentNode->hasLeft())
		{
			// First the line connects the root and the node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			// Draws the node's left at a specific location and selects ut
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		// If the current node only has a right or both then this is called
		if (currentNode->hasRight())
		{
			// A red line is drawn connecting the nodes
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			// Draws the Right node and selects if the only child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);

		}
	}
}
