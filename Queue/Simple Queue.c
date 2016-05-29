#include<stdio.h>
#include<string.h>

int size(int *front,int *rear)
{
	int i, c = 0;
	if (is_empty(front,rear)) {
		return c;
	} else {
		c = *rear - *front + 1;
		return c;
	}
}

int is_full(int n1,int *rear)
{
	if (*rear == n1 - 1) {
		return 1;
	} else {
		return 0;
	}
}

int is_empty(int *front,int *rear)
{
	if (*front == -1 && *rear == -1) {
		return 1;
	} else {
		return 0;
	}
}

void deque(int sq[],int *front,int *rear)
{
	if (is_empty(front,rear)) {
		printf("Simple queue underflow\n");
		return;
	} else if (*front == *rear) {
		printf("%d dequeued\n",sq[*front]);
		*front = *rear = -1;
	} else {
		printf("%d dequeued\n",sq[*front]);
		*front = *front + 1;
	}
}

void enque(int sq[],int n,int n1,int *front,int *rear)
{
	if (is_full(n1,rear)) {
		printf("Simple queue overflow\n");
		return;
	} else if (is_empty(front,rear)) {
		*front = *rear = 0;
	} else {
		*rear = *rear + 1;
	}
	sq[*rear] = n;
	printf("%d enqueued\n",n);
}

int main()
{
	int n1;
	scanf("%d", &n1);
	int sq[n1];
	
	int n2, n, front, rear, i, c;
	front = rear = -1;
	scanf("%d", &n2);
	char s[100];
	for(i = 0; i < n2; i++) {
		scanf("%s", s);
		if (strcmp(s,"enque") == 0) {
			getchar();
			getchar();
			scanf("%d",&n);
			enque(sq,n,n1,&front,&rear);
		} else if (strcmp(s,"deque") == 0) {
			getchar();
			getchar();
			deque(sq,&front,&rear);
		} else {
			c = size(&front,&rear);
			printf("%d\n", c);
		}
	}
	return 0;
}
