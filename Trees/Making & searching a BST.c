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

int search(struct bstnode* node,int value)
{
	if (node == NULL) {
		return 0;
	} else if (node -> data == value) {
		return 1;
	} else if (value <= node -> data) {
		return search(node -> left,value);
	} else {
		return search(node -> right,value);
	}
}

int main()
{
	int choice, v1, v2, x;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Search for an element in the BST\n");
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
				printf("Enter the value to be searched\n");
				scanf("%d", &v2);
				x = search(root,v2);
				if (x == 1) {
					printf("Node with value %d found!!\n",v2);
				} else {
					printf("Node with value %d not found!!\n",v2);
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
