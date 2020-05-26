#include "BSTree.h"

void BSTree::PrintTree(void)
{
	if (root != nullptr)
		root->InOrder();
}
BSTreeNode * BSTree::getRoot() const
{
	return this->root;
}
void BSTree::makeEmpty()
{
	root->makeEmptyRec();
}
bool BSTree::isEmpty()
{
	return(root == nullptr);
}
BSTree::BSTree()
{
	this->root = nullptr;
}

BSTree::~BSTree()
{
	this->makeEmpty();
}

BSTreeNode* BSTree::Find(KeyType k, BSTreeNode**p) const
{
	return this->root->FindRec(k, p);
}
void BSTree::Insert(KeyType k, DataType d, int& NumComp)
{
	BSTreeNode* temp = root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newNode;
	while (temp != nullptr)
	{
		parent = temp;
		if (k < temp->key)
		{

			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
		NumComp++;
	}
	newNode = new BSTreeNode(k, d, NULL, NULL);
	if (parent == nullptr)
		root = newNode;
	else if (k < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
	NumComp++;
}

void BSTree::Delete(KeyType key)
{
	this->root->deleteRec(key);
}


BSTreeNode* BSTree::Max() const
{
	if (this->root != nullptr)
		return this->root->Max();
	return nullptr;
}

BSTreeNode * BSTree::Min() const
{
	if (this->root != nullptr)
		return this->root->Min();
	return nullptr;
}

void BSTree::PrintTreeLimitedByKey(int key)
{
	if (this->root != nullptr)
		root->InOrderWithLimits(key);
}

