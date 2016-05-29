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
struct clinkedlist* insert_last(struct clinkedlist * last,int value)
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
    last = temp;
    return last;
}

struct clinkedlist* insert_after_x(struct clinkedlist * last,int value,int p)
{
	struct clinkedlist* start, *temp, *a;
	temp = (struct clinkedlist*) malloc (sizeof(struct clinkedlist));
	temp -> item = value;
	int i, c = 1;
	start = last -> next;
	while (start -> next != last -> next) {
		c++;
		start = start -> next;
	}
	printf("%d\n", c);
	a = last;
	for (i = 0; i < p; i++) {
		a = a -> next;
	}
	if (p == c) {
		temp -> next = a -> next;
		a -> next = temp;
		last = temp;
	} else {
		temp -> next = a -> next;
		a -> next = temp;
	}
	return last;
}

struct clinkedlist * delete_head(struct clinkedlist * last)
{
	struct clinkedlist * temp;
	struct clinkedlist * temp1;
	temp = last;
	temp1 = temp -> next;
	if (temp == NULL) {
		printf("List Already Empty!\n");
		return last;
	}
	if (temp -> next == temp) {
		last = NULL;
		return last;
	}
	temp -> next = temp -> next -> next;
	free(temp1);
	return last;
}

struct clinkedlist * delete_x(struct clinkedlist * last,int p)
{
	struct clinkedlist * temp, *a;
	a = last;
	int i;
	for (i = 0; i < p - 1; i++) {
		a = a -> next;
	}
	temp = a -> next;
	if (a == temp) {
		free(temp);
		last = NULL;
	} else if (temp == last) {
		a -> next = temp -> next;
		free(temp);
		last = a;
	} else {
		a -> next = temp -> next;
		free(temp);
	}
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

void print_odd(struct clinkedlist * last)
{
	struct clinkedlist * temp;
	temp = last;
	if (temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	temp = temp -> next;
	int i, n;
	if (size(last) % 2 == 0) {
		n = size(last) / 2;
	} else {
		n = size(last) / 2 + 1;
	}
	for(i = 0; i < n ; i++) {
		printf("%d ", temp -> item);
		temp = temp -> next -> next;
	}
	printf("\n");
}

int size(struct clinkedlist * last)
{
	int c;
	c = 0;
	if (last == NULL) {
		return c;
	}
	struct clinkedlist * temp;
	temp = last;
	c = 1;
	if (temp -> next == last) {
		return c;
	}
    temp = temp -> next;
    while(temp != last) {
    	c++;
		temp = temp -> next;
    }
    return c;
}

void search(struct clinkedlist* last,int value)
{
	int c = 0;
	struct clinkedlist * temp;
    temp = last;
    if (temp == NULL) {
    	printf("List is Empty!!\n");
    	return;
	}
	if (temp -> item == value) {
		printf("%d found in  last node\n",value);
    	return;
	}
	temp = temp -> next;
	while(temp != last) {
		c++;
    	if (temp -> item == value) {
    		printf("%d found in node %d\n",value,c);
    		return;
		}
		temp = temp -> next;
	}
	printf("%d Not Found!!\n",value);
}

int main()
{
	struct clinkedlist* last;
	last = NULL;
	int choice;
	int value;
	int p;
	int s;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at last\n");  
		printf("3. Insert after node x\n");  
		printf("4. Remove the first node\n");
		printf("5. Remove the xth node\n");    
		printf("6. Print all the nodes\n");  
		printf("7. Print all the odd nodes\n");  
		printf("8. Size of the List\n");  
		printf("9. Search a value\n");  
		printf("10. Exit\n");
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
				printf("Enter value to be inserted:\n");
                scanf("%d", &value);
                last = insert_last(last,value);
                break ;
			case 3:
				printf("Enter value to be inserted:\n");
				scanf("%d", &value);
				printf("Enter the position of node after which you want to insert:\n");
				scanf("%d", &p);
				last = insert_after_x(last,value,p);
				break ;
			case 4:
				last = delete_head(last);
				break ;
			case 5:
				printf("Enter the position of node which you want to delete:\n");
				scanf("%d", &p);
				last = delete_x(last,p);
				break;
			case 6:
				print_all(last);
				break ;
			case 7:
				print_odd(last);
				break ;
			case 8:
				s = size(last);
				printf("%d\n",s);
				break ;
			case 9:
				printf("Enter the value to search:\n");
				scanf("%d", &value);
				search(last,value);
				break ;
			case 10:
				exit(1);
			default:
				printf("Invalid Choice!\n");		
		}
	}
	return 0;
}
