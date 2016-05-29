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

void enqueue(struct bstnode *queue[],int *front,int *rear,struct bstnode *node)
{
	if (is_empty(front,rear)) {
		*front = *rear = 0;
	} else {
		*rear = *rear + 1;
	}
	queue[*rear] = node;
}

void dequeue(int *front,int *rear)
{
	if (is_empty(front,rear)) {
		printf("Queue Already empty!!\n");
	} else if (*front == *rear) {
		*front = *rear = -1;
	} else {
		*front = *front + 1;
	}
}

int is_empty(int *front,int *rear)
{
	if ((*front == -1) && (*rear == -1)) {
		return 1;
	} else {
		return 0;
	}
}

void levelorder(struct bstnode *queue[],int *front,int *rear,struct bstnode *node)
{
	if (node == NULL) {
		return;
	}
	enqueue(queue,front,rear,node);
	while (!is_empty(front,rear)) {
		struct bstnode *current;
		current = queue[*front];
		printf("%d ",current -> data);
		if (current -> left != NULL) {
			enqueue(queue,front,rear,current -> left);
		}
		if (current -> right != NULL) {
			enqueue(queue,front,rear,current -> right);
		}
		dequeue(front,rear);
	}
}

int main()
{
	int choice, v1, v2;
	struct bstnode* queue[100];
	int front = -1;
	int rear = -1;
	struct bstnode* root;
	root = NULL;
	
	while(1) {
		printf("Choices:\n");
		printf("1. Insert an element in the BST\n");
		printf("2. Level order traversal of a BST\n");
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
				levelorder(queue,&front,&rear,root);
				printf("\n");
				break;
			case 3:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
