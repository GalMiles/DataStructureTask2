#include "BSTreeNode.h"

BSTreeNode::BSTreeNode(KeyType key, DataType data, BSTreeNode * left, BSTreeNode * right): data(data)
{
	this->key = key;
	this->left = left;
	this->right = right;
	this->childrenLeft = 0;
	this->childrenRight = 0;
}

BSTreeNode::~BSTreeNode()
{
	
}
void BSTreeNode::makeEmptyRec()
{
	if (this==nullptr)
		return;

	this->left->makeEmptyRec();
	this->right->makeEmptyRec();
	delete this;
}
BSTreeNode * BSTreeNode::FindRec(KeyType k, int & NumComp)
{
	BSTreeNode *temp = this;
	while (temp != nullptr)
	{
		if (k == temp->key)
			return temp;
		else if (k < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
		NumComp++;
	}
	return nullptr;
}
BSTreeNode * BSTreeNode::FindRec(KeyType k, BSTreeNode ** p)
{
	BSTreeNode*tempP = nullptr;
	BSTreeNode* temp = this;

	while (temp != nullptr)
	{
		if (k == temp->key)
		{
			*p = tempP;
			return temp;
		}
		else if (k < temp->key)
		{
			tempP = temp;
			temp = temp->left;
		}
		else
		{
			tempP = temp;
			temp = temp->right;
		}

	}
	return nullptr;

}
void BSTreeNode::deleteRec(KeyType key)
{
	BSTreeNode* temp1 = this;
	BSTreeNode*p;
	BSTreeNode*temp2;
	BSTreeNode*v = FindRec(key, &p);
	if (v->left == nullptr || v->right == nullptr)//doesnt have one child
	{
		if (p == nullptr)//i want to delete root
		{
			if (v->left == nullptr)
				temp1 = v->right;
			else
				temp1 = v->left;
		}
		else if (v->right == nullptr&&v->left == nullptr)
		{
			if (p->left == v)
				p->left = nullptr;
			else
				p->right = nullptr;
		}
		else if (v->left != nullptr && p->left == v)
			p->left = v->left;
		else if (v->left != nullptr && p->right == v)
			p->right = v->left;
		else if (v->right != nullptr && p->left == v)
			p->left = v->right;
		else if (v->right != nullptr && p->right == v)
			p->right = v->right;
		delete v;
	}
	else
	{
		BSTreeNode *r = v->left->Max();
		v->key = r->key;
		v->data = r->data;
		if (v->key == v->left->key)
		{
			temp2 = v->left;
			v->left = v->left->left;
			delete temp2;
		}
		else
           v->left->deleteRec(v->key);
	}
}
BSTreeNode* BSTreeNode::Max()
{
	BSTreeNode* temp = this;
	while (temp->right)
	{
		temp = temp->right;
	}
	return temp;
}

BSTreeNode* BSTreeNode::Min()
{
	BSTreeNode* temp = this;
	while (temp->left)
	{
		temp = temp->left;
	}
	return temp;
}

void BSTreeNode::InOrder() const
{
	if (this == nullptr)
		return;
	else
	{
		this->left->InOrder();
		cout << this->key << ' ';
		this->right->InOrder();
	}
}

void BSTreeNode::InOrderWithLimits(int keyToStop) const
{
	if (this->key >= keyToStop)
		return;
	else
	{
		this->left->InOrder();
		cout << this->key << ' ';
		this->right->InOrder();
	}
}


void BSTreeNode::PostOrder()const
{
	if (this == nullptr)
		return;
	else
	{
		this->left->PostOrder();
		this->right->PostOrder();
		cout << this->key << ' ';
	}
}

void BSTreeNode::PreOrder()const
{
	if (this == nullptr)
		return;
	else
	{
		cout << this->key << ' ';
		this->left->PreOrder();
		this->right->PreOrder();
	}
}

KeyType BSTreeNode::getKey()const
{
	return this->key;
}

DataType BSTreeNode::getData()const
{
	return this->data;
}

BSTreeNode * BSTreeNode::getLeft()const
{
	return this->left;
}

BSTreeNode * BSTreeNode::getRight()const
{
	return this->right;
}

int BSTreeNode::getNumOfChildrenLeft()const
{
	return this->childrenLeft;
}
