#ifndef BS_H
#define BS_H
#include "BSTreeNode.h"
#include <iostream>
using namespace std;

class BSTree {
private:
	BSTreeNode* root;

public:
	BSTree();
	~BSTree();
	void Insert(KeyType k, DataType d, int &NumComp);
	void Delete(KeyType key);
	BSTreeNode* Find(KeyType k, BSTreeNode**p) const;
	BSTreeNode* Max() const;
	BSTreeNode* Min()const;
	void PrintTree();
	BSTreeNode *getRoot()const;
	void makeEmpty();
	bool isEmpty();
	void PrintTreeLimitedByKey(int key);
};

#endif // !BS_H
