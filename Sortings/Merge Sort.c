#include<stdio.h>

void merge(int left[],int l,int right[],int r,int A[])
{
	int i, j, k;
	i = j = k = 0;
	while (i < l && j < r) {
		if (left[i] <= right[j]) {
			A[k] = left[i];
			i++;
		} else {
			A[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < l) {
		A[k] = left[i];
		i++;
		k++;
	}
	while (j < r) {
		A[k] = right[j];
		j++;
		k++;
	}
}

void merge_sort(int A[], int n)
{
	int i, j, mid;
	if (n < 2) {
		return;
	}
	mid = n / 2;
	int left[mid];
	int right[n - mid];
	for(i = 0; i < mid; i++) {
		left[i] = A[i];
	}
	for(i = mid; i < n; i++) {
		right[i - mid] = A[i];
	}
	merge_sort(left,mid);
	merge_sort(right,n - mid);
	merge(left,mid,right,n-mid,A);
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
	merge_sort(A,n);
	for(i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
