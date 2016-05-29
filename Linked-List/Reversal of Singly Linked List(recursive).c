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

void print_odd(struct linkedlist * start)
{
	struct linkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	
	while(temp != NULL) {
		printf("%d ", temp -> item);
		if (temp -> next == NULL || temp -> next -> next == NULL) {
			break;
		}
		temp = temp -> next -> next;
		
	}
	printf("\n");
}

struct linkedlist* reverse(struct linkedlist *start)
{
	struct linkedlist *temp;
	struct linkedlist *temp1;
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
	temp1 -> next = temp;
	temp -> next = NULL;
	return start;
}

int main()
{
	struct linkedlist* start;
	start = NULL;
	int choice;
	int value;
	int p;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Print all the nodes\n");  
		printf("3. Print all the odd nodes\n");  
		printf("4. Reverse the List\n"); 
		printf("5. Exit\n");
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
				print_odd(start);
				break ;
			case 4:
				start = reverse(start);
				break ;
			case 5:
				exit(1);
			default:
				printf("Invalid Choice!\n");		
		}
	}
	return 0;
}
