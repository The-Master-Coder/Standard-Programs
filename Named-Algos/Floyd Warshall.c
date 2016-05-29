#include<stdio.h>
#include<stdlib.h>

void floyd_warshall(int n, int A[n][n], int D[n][n], int P[n][n])
{
	int i, j, k;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if (A[i][j] == 0 && i != j) {
				D[i][j] = 9999;
			} else {
				D[i][j] = A[i][j];
			}
	
			if (A[i][j] == 0) {
				P[i][j] = -1;
			} else {
				P[i][j] = i + 1;
			}
		}	
	}

	for(k = 0; k < n; k++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[k][j];
				}
			}
		}
	}
	
	for(i = 0; i < n; i++) {
		if (D[i][i] < 0) {
			printf("Error: Negative cycle\n");
			exit(1);
		}
	}
}

void path_finder(int s, int d, int n, int P[n][n])
{
	int A[100], c = 0, i;
	while (d != s) {
		A[c] = d;
		c++;
		d = P[s - 1][d - 1];
	}
	A[c] = s;
	for(i = c; i >= 0; i--) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	int n, i, j, t, s, d;
	scanf("%d", &n);
	int A[n][n];
	int D[n][n];
	int P[n][n];
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	floyd_warshall(n,A,D,P);
	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		scanf("%d %d", &s, &d);
		if (D[s - 1][d - 1] == 9999) {
			printf("Path does not exist\n");
			continue;
		} else if (D[s - 1][d - 1] == 0){
			printf("%d\n", D[s - 1][d - 1]);
			printf("Path does not exist\n");	
		} else {
			printf("%d\n", D[s - 1][d - 1]);
			path_finder(s,d,n,P);
		}
	}
	return 0;
}
