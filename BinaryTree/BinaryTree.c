#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

BTN* createNode(int data)
{
	BTN *newNode = (BTN*)malloc(sizeof(BTN));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void LeftSubChild(BTN **pRoot, int data)
{
	BTN *newNode = createNode(data);
	BTN *ptr;

	if ((*pRoot) == NULL)
	{
		(*pRoot) = newNode;
		return;
	}
	for (ptr = (*pRoot); ptr->left != NULL; ptr = ptr->left);
	ptr->left = newNode;
}
void RightSubChild(BTN **pRoot, int data)
{
	BTN *newNode = createNode(data);
	BTN *ptr;

	if ((*pRoot) == NULL)
	{
		(*pRoot) = newNode;
		return;
	}
	for (ptr = (*pRoot); ptr->right != NULL; ptr = ptr->right);
	ptr->right = newNode;
}
void Inorder(BTN *pRoot)
{
	if (pRoot != NULL)
	{
		Inorder(pRoot->left);
		printf("%d ", pRoot->data);
		Inorder(pRoot->right);
	}
}
void Preorder(BTN *pRoot)
{
	if (pRoot != NULL)
	{
		printf("%d ", pRoot->data);
		Inorder(pRoot->left);
		Inorder(pRoot->right);
	}
}
void Postorder(BTN *pRoot)
{
	if (pRoot != NULL)
	{
		Inorder(pRoot->left);
		Inorder(pRoot->right);
		printf("%d ", pRoot->data);
	}
}
int main()
{
	BTN *pRoot = NULL;
	
	LeftSubChild(&pRoot, 10);
	RightSubChild(&pRoot, 3);
	RightSubChild(&pRoot, 5);
	LeftSubChild(&pRoot, 2);
	RightSubChild(&pRoot, 8);

	printf("Inorder : ");
	Inorder(pRoot);
	printf("\n");

	printf("Preorder : ");
	Preorder(pRoot);
	printf("\n");

	printf("Postorder : ");
	Postorder(pRoot);
	printf("\n");
}