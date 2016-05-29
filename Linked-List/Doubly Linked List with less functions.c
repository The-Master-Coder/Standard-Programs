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

void insert_after_x(struct dlinkedlist * start,int value,int p)
{
	
	int i;
	struct dlinkedlist * temp;
	temp = (struct dlinkedlist*)malloc(sizeof(struct dlinkedlist));
    temp -> item = value;
    temp -> prev = NULL;
    temp -> next = NULL;
	struct dlinkedlist * temp1;
	temp1 = start;
	for(i = 0; i < p - 1; i++) {
		temp1 = temp1 -> next;
	}
	temp -> next = temp1 -> next;
	if (start -> next == NULL) {
		temp1 -> next = temp;
		temp -> prev = temp1;
		printf("%d inserted\n",value);
		return;
	}
	temp1 -> next -> prev = temp;
	temp1 -> next = temp;
	temp -> prev = temp1;
	printf("%d inserted\n",value);
}

struct dlinkedlist * delete_x(struct dlinkedlist * start,int v)
{
	struct dlinkedlist * temp;
	struct dlinkedlist * temp1;
	temp = start;
	if (temp -> item == v) {
		if (temp -> next == NULL) {
			start = temp -> next;
			free(temp);
			return start;
		}
		temp1 = temp -> next;
		start = temp1;
		temp1 -> prev = NULL;
		return start;
	}
	while (temp -> item != v) {
		temp = temp -> next;
	}
	temp1 = temp -> prev;
	if (temp -> next == NULL) {
		temp1 -> next = temp -> next;
		free(temp);
		return start;
	}
	temp -> next -> prev = temp1;
	temp1 -> next = temp -> next;
	free(temp);
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

void rev_print_all(struct dlinkedlist * start)
{
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	while(temp != NULL) {
		printf("%d ", temp -> item);
		temp = temp -> prev;
	}
	printf("\n");
}

int main()
{
	struct dlinkedlist* start;
	start = NULL;
	int choice;
	int value;
	int p, v;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");  
		printf("2. Insert after node x\n");  
		printf("3. Remove the node having value x\n");
		printf("4. Print all the nodes\n");
		printf("5. Reverse print all the nodes\n");    
		printf("6. Exit\n");
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
				printf("Enter value to be inserted:\n");
				scanf("%d", &value);
				printf("Enter the position of node after which you want to insert:\n");
				scanf("%d", &p);
				insert_after_x(start,value,p);
				break ;
			case 3:
				printf("Enter the value of node which you want to delete:\n");
				scanf("%d", &v);
				start = delete_x(start,v);
				break;
			case 4:
				print_all(start);
				break ;
			case 5:
				rev_print_all(start);
				break ;
			case 6:
				exit(1);
			default:
				printf("Invalid Choice!\n");
				break;
		}
	}
	return 0;
}
