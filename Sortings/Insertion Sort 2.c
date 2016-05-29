//Left part is always sorted and right unsorted, we take
//the first element from right and insert it at its correct position in left and so on.
#include<stdio.h>

void insertion_sort(int A[],int n)
{
	int i, j, value;
	for(i = 1; i < n; i++) {
		value = A[i];
		for(j = i - 1; j >= 0 && A[j] > value; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = value;
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
