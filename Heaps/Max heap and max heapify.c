#include<stdio.h>
#include<limits.h>

void swap(int a,int b,int heap[])
{
	int temp;
	temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void max_heapify(int i,int n,int heap[])
{
	int l, r, largest;
	l = 2 * i;
	r = 2 * i + 1;
	largest = i;
	if (l <= n && heap[l] > heap[largest]) {
		largest = l;
	}
	if (r <= n && heap[r] > heap[largest]) {
		largest = r;
	}
	swap(largest,i,heap);
	if (largest != i) {
		max_heapify(largest,n,heap);
	}
}

void build_heap(int n,int heap[])
{
	int i;
	for(i = n/2; i >= 1; i--) {
		max_heapify(i,n,heap);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int heap[100];
	heap[0] = INT_MAX;
	for(i = 1; i < n + 1; i++) {
		scanf("%d", &heap[i]);
	}
	for(i = 1; i < n + 1; i++) {
		printf("%d ",heap[i]);
	}
	printf("\n");
	build_heap(n,heap);
	for(i = 1; i < n + 1; i++) {
		printf("%d ",heap[i]);
	}
	printf("\n");
	return 0;
}
