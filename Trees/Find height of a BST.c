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

int height(struct bstnode *node)
{
	int l, r;
	if (node == NULL) {
		return -1;
	}
	l = height(node -> left);
	r = height(node -> right);
	if (l > r) {
		return l + 1;
	} else {
		return r + 1;
	}
}

int main()
{
	int choice, v1, x;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Find height of the BST\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted\n");
				scanf("%d", &v1);
				root = insert(root,v1);
				break;
			case 2:
				x = height(root);
				if (x == -1) {
					printf("BST is Empty!!\n");
				} else {
					printf("Height of the BST is %d!!\n",x);
				}
				break;
			case 3:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
