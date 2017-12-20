#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef struct _BinaryTreeNode
{
	int data;
	struct _BinaryTreeNode *left;
	struct _BinaryTreeNode *right;
}BTN;

BTN* createNode(int data);
void LeftSubChild(BTN **pRoot, int data);
void RightSubChild(BTN **pRoot, int data);
void Inorder(BTN *pRoot);
#endif 
