#include<stdio.h>
#include<stdlib.h>
struct BinaryTree
{
	int data;
	struct BinaryTree *next,*prev;
};
struct BinaryTree *root;
struct BinaryTree *BuildBinaryTree(int InOrder[],int PreOrder[],int inOrderStart,int inOrderEnd)
{
	static int PreOrderIndex = 0;
	struct BinaryTree *newNode;
	if(inOrderStart>inOrderEnd)
	{
		return NULL;
	}
	newNode = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	newNode->data = preOrder(PreOrderIndex);
	preOrderIndex++;
	if(inOrderStart == inOrderEnd)
	{
		return newNode;
	}
	int inOrderIndex = Search(inOrder,inOrderStart,inOrderEnd,newNode->data);
	newNode->left = BinaryTree(inOrder,preOrder,inOrderIndex,inOrderIndex-1);
	newNode->right = BinaryTree(inOrder,preOrder,inOrderIndex+1,inOrderEnd);
	return newNode;
}
		
