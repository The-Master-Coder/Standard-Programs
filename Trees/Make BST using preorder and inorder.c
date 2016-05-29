#include<stdio.h>
#include<stdlib.h>

struct node {
	int dat;
	struct node * left;
	struct node * right;
};

int search( int * a,int l,int r,int x)
{
	int i;
	for( i = l; i <= r; i++) {
		if( a[i] == x) {
			return i;
		}
	}
}

void inorder( struct node * node)
{
	if( node == NULL) {
		return;
	}
	inorder(node->left);
	printf("%d ",node->dat);
	inorder(node->right);
}

void preorder( struct node * node) 
{
	if( node == NULL) {
		return ;
	}
	printf("%d ",node->dat);
	preorder(node->left);
	preorder( node->right);
}

struct node * buildtree( int * in,int * pre,int l,int r,int * j)
{
	int index;
	if( l > r) {
		return NULL;
	}
	struct node * temp;
	temp = ( struct node * )malloc( sizeof(struct node));
	temp->dat = pre[*j];
	printf("l %d r %d *j %d %d temp->dat",l,r,*j,temp->dat);
	temp->left = NULL;
	temp->right = NULL;
	*j = *j + 1;
	if( l == r ) {
		return temp;
	}
	index = search(in,l,r,temp->dat); 
	printf("index %d\n",index);
	temp->left = buildtree( in,pre,l,index - 1,j);
	temp->right = buildtree(in,pre,index + 1,r,j);
	return temp;
}

int main()
{
	struct node * root;
	int in[100];
	int pre[100];
	int n;
	int i;
	int j;
	j = 0;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		scanf("%d",&in[i]);
	}
	for( i = 0; i < n; i++) {
		scanf("%d",&pre[i]);
	}
	root = buildtree(in,pre,0,n-1,&j);
	printf("\n");
	inorder(root);
	printf("\n");
	preorder(root);
}
