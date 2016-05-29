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

struct dlinkedlist* reverse(struct dlinkedlist *start)
{
	struct dlinkedlist *temp, *temp1;
	temp = start;
	if (temp == NULL) {
		printf("List is empty!!\n");
		return start;
	}
	if (temp -> next == NULL) {
		start = temp;
		return start;
	}
	start = reverse(temp -> next);
	temp1 = temp -> next;
	if (temp1 == start) {
		temp1 -> prev = NULL;
	}
	temp -> prev = temp1;
	temp1 -> next = temp;
	temp -> next = NULL;
	return start;
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
		printf("3. Reverse the list\n");
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
				start = reverse(start);
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
