#include<stdio.h>
#include<stdlib.h>

struct clinkedlist
{
	int item;
	struct clinkedlist* next;
};

struct clinkedlist* insert_beg(struct clinkedlist * last,int value)
{
	struct clinkedlist * temp;
	temp = (struct clinkedlist*)malloc(sizeof(struct clinkedlist));
	temp -> item = value;
	if (last == NULL) {
		temp -> next = temp;
		last = temp;
		return last;
	}
	temp -> next = last -> next;
	last -> next = temp;
	return last;
}

void print_all(struct clinkedlist * last)
{
	struct clinkedlist * temp;
	temp = last;
	if (temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	temp = temp -> next;
	do {
		printf("%d ", temp -> item);
		temp = temp -> next;
	} while(temp != last -> next);
	printf("\n");
}

int sum_of_even_nodes(struct clinkedlist * last)
{
	struct clinkedlist * temp;
	struct clinkedlist * start;
	int sum = 0;
	temp = last;
	if (temp == NULL) {
		return 0;
	}
	temp = temp -> next;
	start = temp;
	if ((temp -> item) % 2 == 0) {
			sum = sum + (temp -> item);
	}
	temp = temp -> next;
	while (temp != start) {
		if ((temp -> item) % 2 == 0) {
			sum = sum + (temp -> item);
		}
		temp = temp -> next;
	}
	return sum;
}

int main()
{
	struct clinkedlist* last;
	last = NULL;
	int choice;
	int value;
	int s;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Print all the nodes\n");
		printf("3. Print sum of all even numbers\n");
		printf("4. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice); 
		
		switch(choice)
		{
			case 1:
				printf("Enter value to be inserted:\n");
				scanf("%d", &value);
				last = insert_beg(last,value);
				break ;
			case 2:
				print_all(last);
				break ;
			case 3:
				s = sum_of_even_nodes(last);
				if (s != 0) {
					printf("%d\n", s);
					break;
				}
				printf("List is Empty\n");
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Choice!\n");		
		}
	}
	return 0;
}
