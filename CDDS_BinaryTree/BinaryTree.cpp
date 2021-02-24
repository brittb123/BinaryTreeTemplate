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

	TreeNode* parent = m_root;;

	while(current != nullptr)
	{
		// IF the value is less than this piece of code is called
		if(value < current->getData())
		{
			// The parent is set to be the current
			parent = current;
			
			// Current is set to be the left of the parent 
			current = current->getLeft();
		}

		// IF the value is More than this piece of code is called
        else if (current->getData() < value)
		{
			// The parent is set to be the current
			parent = current;

			// Current is set to be the right of the parent 
			current = current->getRight();
		}

		else if (value == current->getData())
			return;
	}

	// If the parent's left is null a new node is made with the value and placed at the location
	if (parent->getData() < value)
		parent->setRight(new TreeNode(value));


	// If the parent's left is null a new node is made with the value and placed at the location
	 if (parent->getData() > value)
		 parent->setLeft(new TreeNode(value));
		
}

 void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove
	//and another to hold a reference to its parent.

	TreeNode* Remove = m_root;
	TreeNode* Parent = m_root;


	//Try to find the node that matches the value given and its parent in the tree.
	findNode(value, Remove, Parent);

	//If the node cannot be found return.
	if (!find(value))
		return;

	//Check to see if the node has a right
	if (Remove->hasRight())
	{
		TreeNode* Iterator = m_root;
		TreeNode* secondIterator = m_root;

		Remove->setRight(Iterator);

		while (Iterator->hasLeft())
		{
			secondIterator->setData(Iterator->getData());
			Iterator = Iterator->getLeft();
		}

		Remove->setData(Iterator->getData());

		if (secondIterator->hasLeft())
		{
			if (secondIterator->getLeft()->getData() == Remove->getData())
			{
				secondIterator->setLeft(Iterator->getRight());
			}
		}

		if (secondIterator->hasRight())
		{
			if (secondIterator->getRight()->getData() == Remove->getData())
			{
				secondIterator->setRight(Iterator->getLeft());
			}
		}

		delete(Iterator);
	}

	else
	{
		if (Parent->hasLeft())
		{
			if (Parent->getLeft()->getData() == Remove->getData())
			{
				Parent->setLeft(Remove->getLeft());
			}
		}

		if (Parent->hasRight())
		{
			if (Parent->getRight()->getData() == Remove->getData())
			{
				Parent->setRight(Remove->getRight());
			}
		}

		if (Remove == m_root)
			m_root = m_root->getLeft();

		delete(Remove);
	}
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
			current = current->getLeft();
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
	draw(m_root, 400, 40, 400, selected);
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	//and the other to hold a reference to the parent.

	TreeNode* parent= m_root;
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
	horizontalSpacing /= 2;

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

		currentNode->draw(x, y, (selected == currentNode));
	}
}
