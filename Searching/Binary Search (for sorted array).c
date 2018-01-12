#include<stdio.h>

void binary_search(int A[],int start,int end,int value)
{
	int mid;
	if (start > end) {
		printf("Element Not Found!!\n");
		return ;
	}
	mid = start + (end - start) / 2;
	if (A[mid] == value) {	
		printf("Element Found!!\n");
		return ;
	} else if (value > A[mid]) {
		start = mid + 1;
		binary_search(A,start,end,value);
	} else {
		end = mid - 1;
		binary_search(A,start,end,value);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	int start;
	int end;
	start = 0;
	end = n - 1;
	int value;
	scanf("%d", &value);
	binary_search(A,start,end,value);
	return 0;
}
	
