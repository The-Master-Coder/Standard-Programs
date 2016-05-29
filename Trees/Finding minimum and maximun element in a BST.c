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

int find_min(struct bstnode* node)
{
	if (node == NULL) {
		return -99;
	} else if (node -> left == NULL) {
		return node -> data;
	}
	return find_min(node -> left);
}

int find_max(struct bstnode* node)
{
	if (node == NULL) {
		return -99;
	} else if (node -> right == NULL) {
		return node -> data;
	}
	return find_max(node -> right);
}

int main()
{
	int choice, v1, x, y;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Find the minimum element in the BST\n");
		printf("3. Find the maximum element in the BST\n");
		printf("4. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted\n");
				scanf("%d", &v1);
				root = insert(root,v1);
				break;
			case 2:
				x = find_min(root);
				if (x == -99) {
					printf("BST is Empty!!\n");
				} else {
					printf("Min elemnt of BST is %d\n",x);
				}
				break;
			case 3:
				y = find_max(root);
				if (y == -99) {
					printf("BST is Empty!!\n");
				} else {
					printf("Max elemnt of BST is %d\n",y);
				}
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
