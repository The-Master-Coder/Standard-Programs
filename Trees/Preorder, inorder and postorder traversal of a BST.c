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

int main()
{
	int choice, v1, v2, x;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Preorder traversal\n");
		printf("3. Inorder traversal\n");
		printf("4. Postorder traversal\n");
		printf("5. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted\n");
				scanf("%d", &v1);
				root = insert(root,v1);
				break;
			case 2:
				preorder(root);
				printf("\n");
				break;
			case 3:
				inorder(root);
				printf("\n");
				break;
			case 4:
				postorder(root);
				printf("\n");
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
