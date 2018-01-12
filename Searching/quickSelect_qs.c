//ASSUMPTION: ALL ELEMENTS IN A[] ARE DISTINCT
#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int a, int b)
{
    int temp = A[a];
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

int kthSmallest(int A[], int l, int r, int k)
{
    int pos = partition(A, l, r);
    if (pos == k-1) {
        return A[pos];
    }
    if (pos > k-1) {
         return kthSmallest(A, l, pos-1, k);
    } else {
         return kthSmallest(A, pos+1, r, k);
    }
}

int main()
{
    int n, k, i, x;
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    while(1) {
        scanf("%d", &k);
        if (k > 0 && k <= n) {
            x = kthSmallest(A, 0, n-1, k);
            printf("%d\n", x);
        } else {
            printf("Invalid query!\n");
        }
    }  
    return 0;
}