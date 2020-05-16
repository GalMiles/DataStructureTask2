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
	BSTreeNode* Find(KeyType k, int& NumComp) const;
	void Insert(KeyType k, DataType* d, int &NumComp);
	void Delete(KeyType key);
	BSTreeNode* Find(KeyType k, BSTreeNode**p) const;
	BSTreeNode* Max() const;
	BSTreeNode* Min()const;
	void PrintTree(void);
	BSTreeNode *getRoot()const;
	void makeEmpty();
	bool isEmpty();
};

#endif // !BS_H
