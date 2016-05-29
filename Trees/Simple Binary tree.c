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
	if( i >= n / 2) {
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

void preorder(struct node *root)
{
	if (root == NULL) {
		return;
	}
	printf("%d ",root -> data);
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(struct node *root)
{
	if (root == NULL) {
		return;
	}
	inorder(root -> left);
	printf("%d ",root -> data);
	inorder(root -> right);
}

void postorder(struct node *root)
{
	if (root == NULL) {
		return;
	}
	postorder(root -> left);
	postorder(root -> right);
	printf("%d ",root -> data);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int A[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	struct node * root;
	root = (struct node*)malloc(sizeof(struct node));
	root->data = A[0];
	root->left = NULL;
	root->right = NULL;
	create_bt(A,0,root,n);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}
