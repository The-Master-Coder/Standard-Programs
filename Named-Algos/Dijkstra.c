//Weighted Adjacency Matrix is used
#include<stdio.h>
#define white 0
#define black 1

void path_finder(int s, int d, int n, int P[])
{
	int A[100], c = 0, i;
	while (d != s) {
		A[c] = d;
		c++;
		d = P[d - 1];
	}
	A[c] = s;
	for(i = c; i >= 0; i--) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int min_temp(int n,int color[],int D[])
{
	int i, t = -1;
	int min = 99999;
	for(i = 0; i < n; i++) {
		if (color[i] == white && D[i] < min) {
			min = D[i];
			t = i;
		}
	}
	return t;
}

void dijkstra(int s, int n, int A[n][n], int D[], int P[], int color[])
{
	int i, current;
	for(i = 0; i < n; i++) {
		P[i] = -1;
		D[i] = 99999;
		color[i] = white;
	}
	D[s - 1] = 0;
	while (1) {
		current = min_temp(n,color,D);
		if (current == -1) {
			return;
		}
		color[current] = black;
		for(i = 0; i < n; i++) {
			if (A[current][i] != 0 && color[i] == white) {
				if (D[current] + A[current][i] < D[i]) {
					P[i] = current + 1;
					D[i] = D[current] + A[current][i];
				}
			}
		}
	}
}

int main()
{
	int n, i, j, t, s, d;
	scanf("%d", &n);
	int A[n][n];
	int D[n];
	int P[n];
	int color[n];
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
			if (i != j && A[i][j] == 0) {
				A[i][j] = 99999;
			}
		}
	}
	scanf("%d", &s);
	dijkstra(s,n,A,D,P,color);
	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		scanf("%d",&d);
		if (D[d - 1] == 99999) {
			printf("Path does not exist\n");
			continue;
		} else if (D[d - 1] == 0){
			printf("%d\n", D[d - 1]);
			printf("Path does not exist\n");	
		} else {
			printf("%d\n", D[d - 1]);
			path_finder(s,d,n,P);
		}
	}
	return 0;
}
