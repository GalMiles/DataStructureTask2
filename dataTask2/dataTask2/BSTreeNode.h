#ifndef B_H
#define B_H
#include "Student.h"
#include <iostream>
using namespace std;
typedef int KeyType;
typedef string DataType;

class BSTreeNode {

private:
	KeyType key;
	DataType data;

	BSTreeNode* left, *right;
public:
	BSTreeNode(KeyType key, DataType data, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();
	void InOrder() const;
	void PostOrder()const;
	void PreOrder()const;
	KeyType getKey()const;
	void InOrderWithLimits(int keyToStop) const;
	DataType getData()const;
	BSTreeNode* getLeft()const;
	BSTreeNode* getRight()const;
	friend class BSTree;
	void makeEmptyRec();
	BSTreeNode* FindRec(KeyType k, int& NumComp);
	BSTreeNode* FindRec(KeyType k, BSTreeNode**p);
	void deleteRec(KeyType key);
	BSTreeNode* Max();
	BSTreeNode* Min();
};

#endif // !1
