//Weighted Adjacency Matrix is used
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
	int data;
	struct node *next;
	struct node *repr;
};

void make_set(int value,struct node *A[])
{
	if(A[value] != NULL) {
		return;
	}
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = value;
	temp -> next = NULL;
	temp -> repr = temp;
	A[value] = temp;
}

struct node* find_set(int value,struct node *A[])
{
	return (A[value] -> repr);
}

void unionn(int v1,int v2,struct node *A[])
{
	if (A[v2] == NULL) {
		return;
	}
	if (v1 == v2) {
		return;
	}
	struct node *temp1, *temp2;
	temp1 = A[v1];
	temp2 = A[v2] -> repr;
	
	if (temp1 -> repr -> data != temp2 -> data) {
		while(temp1 -> next != NULL) {
			temp1 = temp1 -> next;
		}
		temp1 -> next = temp2;
		while (temp2 != NULL) {
			temp2 -> repr = A[v1] -> repr;
			temp2 = temp2 -> next;
		}
	}
}

void kruskal(struct node *A[],int n,int B[n][n], int C[],int count)
{
	int i, j, k, l, min, t = 1, sum = 0, x;
	for(i = 1; i <= n; i++) {
		make_set(i,A);
	}
	min = INT_MAX;
	for(l = 0; l < n * n - count; l++) {
		for(k = 0; k < n * n - 1; k++) {
			if (C[k] < min && C[k] != 0) {
				min = C[k];
				x = k;
			}
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(B[i][j] == min) {
					if (find_set(i + 1,A) != find_set(j + 1,A)) {
						printf("Edge %d (%d,%d) = %d\n", t, i + 1, j + 1, B[i][j]);
						t++;
						sum = sum + B[i][j];
						unionn(i + 1, j + 1, A);
					}
				}
			}	
		}
		C[x] = INT_MAX;
		min = INT_MAX;
	}
	printf("\n");
	printf("Minimum cost = %d\n", sum);
}

int main()
{
	int t, n, i, j, k, l, x = 0, count = 0;
	scanf("%d", &t);
	for(i = 0 ; i < t; i++) {
		scanf("%d", &n);
		struct node *A[2 * n];
		for(l = 0; l < 2 * n; l++) {
			A[l] = NULL;
		}
		int B[n][n], C[n * n];
		for(j = 0; j < n; j++) {
			for(k = 0; k < n; k++) {
				scanf("%d", &B[j][k]);
				C[x] = B[j][k];
				if (B[j][k] == 0) {
					count++;
				}
				x++;
			}
		}
		kruskal(A,n,B,C,count);
	}
	return 0;
}
