#include<stdio.h>
#include<stdlib.h>
struct BinarySearchTreeNode
{
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};
struct BinarySearchTreeNode *root;
struct BinarySearchTreeNode *Find(struct BinarySearchTreeNode *root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(data<root->data)
	{
		return Find(root->left,data);
	}
	else if(data>root->data)
	{
		return Find(root->right,data);
	}
	return root;
}
struct BinarySearchTreeNode *Insert(struct BinarySearchTreeNode *root,int data)
{
	if(root == NULL)
	{
		root = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(root->data<data)
	{
		root->right = Insert(root->right,data);
	}
	else if(root->data>data)
	{
		root->left = Insert(root->left,data);
	}
	return root;
}
struct BinarySearchTreeNode *Delete(struct BinarySearchTreeNode *root,int data)
{
	struct BinarySearchTreeNode *temp;
	if(root==NULL)
	{
		printf("there are no elements are there in the tree\n");
	}
	else if(data<root->data)
	{
		root->left = Delete(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = Delete(root->right,data);
	}
	else
	{
		if(root->left && root->right)
		{
			temp = FindMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left,data);
		}
		else
		{
			temp = root;
			if(root->left == NULL)
			{
				root = root->right;
			}
			if(root->right == NULL)
			{
				root = root->left;
			}
			free(root);
		}
	}
	return root;
}
	
