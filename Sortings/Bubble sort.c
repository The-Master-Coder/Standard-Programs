#include<stdio.h>
int main()
{
	int i, j, n, exchanges, temp;
	scanf("%d", &n);
	int A[n];
	
	for(i = 0;i < n; i++) {
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < n-1; i++) {
		exchanges = 0;
		for( j = 0; j < (n-1-i); j++) {
			if (A[j] > A[j +1]) {
				temp = A[j];
				A[j] = A[j +1];
				A[j + 1] = temp;
				exchanges++;
			}
		}
		if (exchanges == 0) {
			break;
		}
	}
	for(i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
