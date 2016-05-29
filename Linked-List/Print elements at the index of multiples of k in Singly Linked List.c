#include<stdio.h>
#include<stdlib.h>

struct linkedlist
{
	int item;
	struct linkedlist* next;
};

struct linkedlist* insert_beg(struct linkedlist * start,int value)
{
	struct linkedlist * temp;
	temp = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	temp -> item = value;
	temp -> next = start;
	start = temp;
	printf("%d inserted\n",value);
	return start;
}

void print_all(struct linkedlist * start)
{
	struct linkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	while(temp != NULL) {
		printf("%d ", temp -> item);
		temp = temp -> next;
	}
	printf("\n");
}

void print_at_index_multiples_of_k(struct linkedlist * start,int k)
{
	struct linkedlist * temp;
	temp = start;
	int i, j, n;
	int c = 1;
	while (temp -> next != NULL) {
		temp = temp -> next;
		c++;
	}
	if (c % k == 0) {
		n = c/k;
	} else {
		n = c/k + 1;
	}
	temp = start;
	printf("%d ", temp -> item);
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < k; j++) {
			temp = temp -> next;
		}
		printf("%d ", temp -> item);
	}
	printf("\n");
}

int main()
{
	struct linkedlist* start;
	start = NULL;
	int choice;
	int value;
	int p, k;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Print all the nodes\n");  
		printf("3. Print elements at index multiples of k\n");
		printf("4. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice); 
		
		switch(choice)
		{
			case 1:
				printf("Enter value to be inserted:\n");
				scanf("%d", &value);
				start = insert_beg(start,value);
				break ;
			case 2:
				print_all(start);
				break ;
			case 3:
				if (start == NULL) {
					printf("List is Empty\n");
					break;
				}
				printf("Enter the value of k\n");
				scanf("%d", &k);
				print_at_index_multiples_of_k(start,k);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Choice!\n");		
		}
	}
	return 0;
}
