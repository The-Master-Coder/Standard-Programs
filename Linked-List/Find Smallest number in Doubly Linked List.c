#include<stdio.h>
#include<stdlib.h>

struct dlinkedlist
{
	int item;
	struct dlinkedlist* prev;
	struct dlinkedlist* next;
};

struct dlinkedlist* insert_beg(struct dlinkedlist * start,int value)
{
	struct dlinkedlist * temp;
	struct dlinkedlist * temp1;
	temp1 = start;
	temp = (struct dlinkedlist*)malloc(sizeof(struct dlinkedlist));
	temp -> item = value;
	temp -> next = start;
	temp -> prev = NULL;
	if (temp1 != NULL) {
		temp1 -> prev = temp;
	}
	start = temp;
	printf("%d inserted\n",value);
	return start;
}

void print_all(struct dlinkedlist * start)
{
	struct dlinkedlist * temp;
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

int find_smallest(struct dlinkedlist * start)
{
	int min;
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		return 0;
	}
	min = temp -> item;
	while (temp -> next != NULL) {
		if (temp -> next -> item < min) {
			min = temp -> next -> item;
		}
		temp = temp -> next;
	}
	return min;
}

int main()
{
	struct dlinkedlist* start;
	start = NULL;
	int choice;
	int value;
	int s;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Print all the nodes\n");
		printf("3. Print the smallest node\n");
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
				s = find_smallest(start);
				if (s != 0) {
					printf("%d\n", s);
					break;
				}
				printf("List is Empty!!\n");
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Choice!\n");
				break;
		}
	}
	return 0;
}
