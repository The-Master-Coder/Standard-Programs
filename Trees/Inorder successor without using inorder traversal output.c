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

struct bstnode* find(struct bstnode* node,int value)
{
	if (node == NULL) {
		return NULL;
	} else if (node -> data == value) {
		return node;
	} else if (value <= node -> data) {
		return find(node -> left,value);
	} else {
		return find(node -> right,value);
	}
}

struct bstnode* find_min(struct bstnode* node)
{
	if (node == NULL) {
		return NULL;
	} else if (node -> left == NULL) {
		return node;
	}
	return find_min(node -> left);
}

int getsuccessor(struct bstnode *node,int value)
{
	struct bstnode * current;
	struct bstnode * temp;
	current = find(node,value);
	if (current == NULL) {
		return -99;
	}
	else if (current -> right != NULL) {
		return (find_min(current -> right)) -> data;
	} else {
		struct bstnode * successor;
		successor = NULL;
		struct bstnode * ancestor;
		ancestor = node;
		while (ancestor != current) {
			if (current -> data < ancestor -> data) {
				successor = ancestor;
				ancestor = ancestor -> left;
			} else {
				ancestor = ancestor -> right;
			}
		}
		temp = successor;
		if (temp == NULL) {
			return -99;
		} else {
			return temp -> data;
		}
	}
}

int main()
{
	int choice, v1, v2, j;
	int A[100];
	int i = 0;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Find the inorder successor of an element in the BST\n");
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
				if (root == NULL) {
					printf("BST is empty!!\n");
					break;
				}
				printf("Enter the value of node of which the successor is required\n");
				scanf("%d", &v2);
				j = getsuccessor(root,v2);
				if (j == -99) {
					printf("%d has no inorder successor or %d does not exist in the BST\n",v2,v2);
				}else {
					printf("Successor of %d is: %d\n",v2,j);
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
