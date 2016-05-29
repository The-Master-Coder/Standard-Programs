#include<stdio.h>
#include<string.h>

int size(int n1,int *front,int *rear)
{
	int i, c = 0;
	if (is_empty(front,rear)) {
		return c;
	} else {
		i = *front;
		c = 1;
		while (i != *rear) {
			c++;
			i = (i +1) % n1;
		}
		return c;
	}
}

int is_full(int n1,int *front,int *rear)
{
	if ((*rear + 1) % n1 == *front) {
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

void deque(int sq[],int n1,int *front,int *rear)
{
	if (is_empty(front,rear)) {
		printf("Circular queue underflow\n");
		return;
	} else if (*front == *rear) {
		printf("%d dequeued\n",sq[*front]);
		*front = *rear = -1;
	} else {
		printf("%d dequeued\n",sq[*front]);
		*front = (*front + 1) % n1;
	}
}

void enque(int sq[],int n,int n1,int *front,int *rear)
{
	if (is_full(n1,front,rear)) {
		printf("Circular queue overflow\n");
		return;
	} else if (is_empty(front,rear)) {
		*front = *rear = 0;
	} else {
		*rear = (*rear + 1) % n1;
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
			deque(sq,n1,&front,&rear);
		} else {
			c = size(n1,&front,&rear);
			printf("%d\n", c);
		}
	}
	return 0;
}
