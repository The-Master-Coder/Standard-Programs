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

int heap_max(int heap[])
{
	return heap[1];
}

int heap_extract_max(int heap[],int *n)
{
	int max;
	max = heap[1];
	heap[1] = heap[*n];
	*n = *n - 1;
	max_heapify(1,*n,heap);
	return max;
}

void heap_delete_element(int heap[],int *n,int v)
{
	int i, j;
	for(i = 1; i < *n + 1; i++) {
		if(heap[i] == v) {
			for(j = i; j < *n; j++) {
				heap[j] = heap[j + 1];
			}
			break;
		}
	}
	*n = *n - 1;
	build_heap(*n,heap);
}

void heap_increase_key(int heap[],int newkey,int n,int i)
{
	heap[i] = newkey;
	build_heap(n,heap);
}

void heap_insert(int heap[],int *n,int v)
{
	int i;
	for(i = *n + 1; i >= 1; i--) {
		heap[i + 1] = heap[i];
	}
	heap[1] = v;
	*n = *n + 1;
	max_heapify(1,*n,heap);
}

void display(int heap[],int n)
{
	int i;
	for(i = 1; i < n + 1; i++) {
		printf("%d ",heap[i]);
	}
	printf("\n");
}

int main()
{
	int n, i, v, max, maxx, value, choice, index, newkey;
	int heap[1000];
	heap[0] = INT_MAX;
	while(1) {
		printf("Choices : \n");
		printf("1. Create a heap\n");
		printf("2. Get maximum value of heap\n");
		printf("3. Insert an element in the heap\n");
		printf("4. Remove an element from heap\n");
		printf("5. Remove the maximum element from heap\n");
		printf("6. Change the value of an element\n");
		printf("7. Display the heap\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				scanf("%d", &n);
				for(i = 1; i < n + 1; i++) {
					scanf("%d", &heap[i]);
				}
				build_heap(n,heap);
				break;
			case 2:
				max = heap_max(heap);
				printf("%d\n",max);
				break;
			case 3:
				scanf("%d", &v);
				heap_insert(heap,&n,v);
				break;
			case 4:
				scanf("%d",&value);
				heap_delete_element(heap,&n,value);
				break;
			case 5:
				maxx = heap_extract_max(heap,&n);
				break;
			case 6:
				scanf("%d", &index);
				scanf("%d", &newkey);
				heap_increase_key(heap,newkey,n,index);
				break;
			case 7:
				display(heap,n);
				break;
			default:
				printf("Invalid choice!\n");
				
		}
	}

	return 0;
}
