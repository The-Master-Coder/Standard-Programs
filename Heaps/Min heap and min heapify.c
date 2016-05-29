#include<stdio.h>
#include<limits.h>

void swap(int a,int b,int heap[])
{
	int temp;
	temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void min_heapify(int i,int n,int heap[])
{
	int l, r, smallest;
	l = 2 * i;
	r = 2 * i + 1;
	smallest = i;
	if (l <= n && heap[l] < heap[smallest]) {
		smallest = l;
	}
	if (r <= n && heap[r] < heap[smallest]) {
		smallest = r;
	}
	swap(smallest,i,heap);
	if (smallest != i) {
		min_heapify(smallest,n,heap);
	}
}

void build_heap(int n,int heap[])
{
	int i;
	for(i = n/2; i >= 1; i--) {
		min_heapify(i,n,heap);
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
