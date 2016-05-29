#include<stdio.h>

void swap(int A[],int a,int b)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

int partition(int A[],int start,int end)
{
	int pivot, i, p_index;
	pivot = A[end];
	p_index = start;
	for(i = start; i < end; i++) {
		if (A[i] <= pivot) {
			swap(A,i,p_index);
			p_index++;
		}
	}
	swap(A,p_index,end);
	return p_index;
}

void quick_sort(int A[],int start,int end)
{
	int p_index;
	if (start >= end) {
		return;
	}
	p_index = partition(A,start,end);
	quick_sort(A,start,p_index - 1);
	quick_sort(A,p_index + 1,end);
}


int main()
{
	int i, n, start, end;
	scanf("%d", &n);
	start = 0;
	end = n - 1;
	int A[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	quick_sort(A,start,end);
	for(i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
