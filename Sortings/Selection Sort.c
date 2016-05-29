//We select the minimum element from the given array and then swap it
//with the first element and so on.
#include<stdio.h>

selection_sort(int A[], int n)
{
	int i, j, temp, min_index;
	
	for(i = 0; i < n - 1; i++) {
		min_index = i;
		for(j = i + 1; j < n; j++) {
			if (A[j] < A[min_index]) {
				min_index = j;
			}
		}
		temp = A[i];
		A[i] = A[min_index];
		A[min_index] = temp;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	selection_sort(A,n);
	for(i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
