#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void create_bt(int A[],int i,struct node * node,int n)
{
	if( i > n / 2) {
		return;
	}
	if( 2 * i + 1 < n) {
		node->left = (struct node *)malloc(sizeof(struct node));
		node->left->data = A[2 * i + 1];
		node->left->left = NULL;
		node->left->right = NULL;
	}
	if( 2 * i + 2 < n) {
		node->right = (struct node *)malloc(sizeof(struct node));
		node->right->data = A[2 * i + 2];
		node->right->left = NULL;
		node->right->right = NULL;
	}
	create_bt(A,2*i + 1,node->left,n);
	create_bt(A,2*i + 2,node->right,n);
	
}

void inorder(struct node *node,int A[],int *t)
{
	if (node == NULL) {
		return;
	}
	inorder(node -> left,A,t);
	A[*t] = node -> data;
	*t = *t + 1;
	inorder(node -> right,A,t);
}

int main()
{
	int n, v, i, t = 0, flag = 0;
	scanf("%d", &n);
	int A[n], B[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	struct node * root;
	root = (struct node*)malloc(sizeof(struct node));
	root->data = A[0];
	root->left = NULL;
	root->right = NULL;
	create_bt(A,0,root,n);
	inorder(root,B,&t);
	for(i = 0; i < t - 1; i++) {
		if (B[i] > B[i + 1]) {
			flag = 1;
			break;
		} else {
			flag = 2;
		}
	}
	if (flag == 1) {
		printf("This BT is not a BST\n");
	} else {
		printf("This BT is a BST\n");
	}
	return 0;
}
