#include<stdio.h>
#include<stdlib.h>

struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

struct bstnode* getnewnode(int value)
{
	struct bstnode * temp;
	temp = (struct bstnode*)malloc(sizeof(struct bstnode));
	temp -> data = value;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

struct bstnode* insert(struct bstnode *node,int value)
{
	if (node == NULL) {
		node = getnewnode(value);
	} else if (value <= node -> data) {
		node -> left = insert(node -> left,value);
	} else {
		node -> right = insert(node -> right,value);
	}
	return node;
}

void preorder(struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	printf("%d ",node -> data);
	preorder(node -> left);
	preorder(node -> right);
}

void inorder(struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	inorder(node -> left);
	printf("%d ",node -> data);
	inorder(node -> right);
}

void postorder(struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	postorder(node -> left);
	postorder(node -> right);
	printf("%d ",node -> data);
}

void print_bst(struct bstnode *root)
{
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}

void mirror(struct bstnode *node)
{
	struct bstnode *temp;
	if (node == NULL) {
		return;
	}
	temp = node -> left;
	node -> left = node -> right;
	node -> right = temp;
	mirror(node -> left);
	mirror(node -> right);
}
int main()
{
	int v, n, i;
	struct bstnode* root;
	root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		root = insert(root,v);
	}
	print_bst(root);
	mirror(root);
	print_bst(root);
	return 0;
}
