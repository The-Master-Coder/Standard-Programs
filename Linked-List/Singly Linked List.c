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
void insert_last(struct linkedlist * start,int value)
{
	struct linkedlist * temp;
	temp = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    temp -> item = value;
    temp -> next = NULL;
    struct linkedlist * temp1;
	temp1 = start;
	if (temp1 == NULL ) {
		temp1 = temp;
		printf("%d inserted\n",value);
		return;
	}
	while(temp1 -> next != NULL) {
		temp1 = temp1 -> next;
    }
	temp1 -> next = temp;
	printf("%d inserted\n",value);
}

void insert_after_x(struct linkedlist * start,int value,int p)
{
	
	int i;
	struct linkedlist * temp;
	temp = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    temp -> item = value;
    temp -> next = NULL;
	struct linkedlist * temp1;
	temp1 = start;
	for(i = 0; i < p - 1; i++) {
		temp1 = temp1 -> next;
	}
	temp -> next = temp1 -> next;
	temp1 -> next = temp;
	printf("%d inserted\n",value);
}

struct linkedlist * delete_head(struct linkedlist * start)
{
	struct linkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List Already Empty!\n");
		return start;
	}
	start = start -> next;
	free(temp);
	return start;
}

struct linkedlist * delete_last(struct linkedlist * start)
{
	struct linkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List is Empty!!\n");
		return start;
	}
	if (temp -> next == NULL) {
		free(temp);
		start = NULL;
		return start;
	}
	while (temp -> next -> next != NULL) {
		temp = temp -> next;
	}
	free(temp -> next);
	temp -> next = NULL;
	return start;
}

struct linkedlist * delete_x(struct linkedlist * start,int p)
{
	struct linkedlist * temp;
	temp = start;
	if (p == 1) {
		start = temp -> next;
		free(temp);
		return start;
	}
	int i;
	for(i = 0; i < p - 2; i++) {
		temp = temp -> next;
	}
	struct linkedlist * temp1;
	temp1 = temp -> next;
	temp -> next = temp1 -> next;
	free(temp1);
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

void size(struct linkedlist * start)
{
	int c;
	c = 0;
	struct linkedlist * temp;
    temp = start;
    while(temp != NULL) {
    	c++;
		temp = temp -> next;
    }
    printf("%d\n", c);
}

int search(struct linkedlist* start,int value)
{
	int c = 0;
	struct linkedlist * temp;
    temp = start;
    if (temp == NULL) {
    	printf("List is Empty!!\n");
	}
    while(temp != NULL) {
    	c++;
    	if (temp -> item == value) {
    		printf("%d found in node %d\n",value,c);
    		return;
		}
		temp = temp -> next;
    }
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
		printf("2. Insert at last\n");  
		printf("3. Insert after node x\n");  
		printf("4. Remove the first node\n");
		printf("5. Remove the last node\n");
		printf("6. Remove the xth node\n");    
		printf("7. Print all the nodes\n");  
		printf("8. Print all the odd nodes\n");  
		printf("9. Size of the List\n");  
		printf("10. Search a value\n"); 
		printf("11. Exit\n");
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
                insert_last(start,value);
                break ;
			case 3:
				printf("Enter value to be inserted:\n");
				scanf("%d", &value);
				printf("Enter the position of node after which you want to insert:\n");
				scanf("%d", &p);
				insert_after_x(start,value,p);
				break ;
			case 4:
				start = delete_head(start);
				break ;
			case 5:
				start = delete_last(start);
				break;
			case 6:
				printf("Enter the position of node which you want to delete:\n");
				scanf("%d", &p);
				start = delete_x(start,p);
				break;
			case 7:
				print_all(start);
				break ;
			case 8:
				print_odd(start);
				break ;
			case 9:
				size(start);
				break ;
			case 10:
				printf("Enter the value to search:\n");
				scanf("%d", &value);
				search(start,value);
				break ;
			case 11:
				exit(1);
			default:
				printf("Invalid Choice!\n");		
		}
	}
	return 0;
}
