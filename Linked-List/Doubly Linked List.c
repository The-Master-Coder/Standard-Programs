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
void insert_last(struct dlinkedlist * start,int value)
{
	struct dlinkedlist * temp;
	temp = (struct dlinkedlist*)malloc(sizeof(struct dlinkedlist));
    temp -> item = value;
    temp -> prev = NULL;
    temp -> next = NULL;
    struct dlinkedlist * temp1;
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
	temp -> prev = temp1;
	printf("%d inserted\n",value);
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

struct dlinkedlist * delete_head(struct dlinkedlist * start)
{
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List Already Empty!\n");
		return;
	}
	int t;
	t = temp -> item;
	if (temp -> next == NULL) {
		start = start -> next;
		free(temp);
		return start;
	}
	start = start -> next;
	temp -> next -> prev = NULL;
	free(temp);
	printf("Head node of value %d deleted\n",t);
	return start;
}

struct dlinkedlist * delete_x(struct dlinkedlist * start,int p)
{
	struct dlinkedlist * temp;
	temp = start;
	if (temp -> next == NULL) {
		start = temp -> next;
		free(temp);
		return start;
	}
	if (p == 1) {
		start = temp -> next;
		temp -> next -> prev = temp -> prev;
		free(temp);
		return start;
	}
	int i;
	for(i = 0; i < p - 2; i++) {
		temp = temp -> next;
	}
	struct dlinkedlist * temp1;
	temp1 = temp -> next;
	if (temp1 -> next == NULL) {
		temp -> next = temp1 -> next;
		free(temp1);
		return start;
	}
	temp -> next = temp1 -> next;
	temp1 -> next -> prev = temp;
	free(temp1);
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


void print_odd(struct dlinkedlist * start)
{
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	while(temp != NULL) {
		printf("%d ", temp -> item);
		if (temp -> next == NULL) {
			break;
		}
		temp = temp -> next -> next;
		
	}
	printf("\n");
}

void size(struct dlinkedlist * start)
{
	int c;
	c = 0;
	struct dlinkedlist * temp;
    temp = start;
    while(temp != NULL) {
    	c++;
		temp = temp -> next;
    }
    printf("%d\n", c);
}

int search(struct dlinkedlist* start,int value)
{
	int c = 0;
	struct dlinkedlist * temp;
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
	struct dlinkedlist* start;
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
		printf("5. Remove the xth node\n");    
		printf("6. Print all the nodes\n");
		printf("7. Reverse print all the nodes\n");  
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
				printf("Enter the position of node which you want to delete:\n");
				scanf("%d", &p);
				start = delete_x(start,p);
				break;
			case 6:
				print_all(start);
				break ;
			case 7:
				rev_print_all(start);
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
				break;
		}
	}
	return 0;
}

