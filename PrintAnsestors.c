int PrintAllAnscestors(struct BinaryTree *root,struct BinaryTree *node)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left == node || root->right == node || PrintAllAnscestors(root->left,node) || PrintAllAnscestors(root->left,node))
	{
		printf("%d",root->data);
		return 1;
	}
	return 0;
}
