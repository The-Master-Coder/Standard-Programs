//If n == odd then Disk 1 : A -> C, if n == even then Disk 1 : A -> B
#include<stdio.h>

void toh(int n, char from, char to, char thru)
{
	if (n == 1) {
		printf("Disk 1 : %c --> %c\n",from,to);
		return;
	}
	toh(n - 1,from,thru,to);
	printf("Disk %d : %c --> %c\n",n,from,to);
	toh(n - 1,thru,to,from);
}

int main()
{
	int n;
	scanf("%d", &n);
	toh(n,'A','C','B');
}
