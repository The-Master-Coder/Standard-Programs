#include<stdio.h>

void insertion_sort(int A[],int n)
{
	int i, value, hole;
	for(i = 1; i < n; i++) {
		value = A[i];
		hole = i;
		while (hole > 0 && A[hole - 1] > value) {
			A[hole] = A[hole - 1];
			hole--;
		}
		A[hole] = value;
	}
}

int main()
{
  	int n, i;
  	scanf("%d", &n);
	int A[n];
  	for(i = 0; i < n; i++) {
  		scanf("%d", &A[i]);
	}
	for(i = 0; i < n; i++) {
  		printf("%d ", A[i]);
	}
	printf("\n");
	insertion_sort(A,n);
	for(i = 0; i < n; i++) {
  		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
