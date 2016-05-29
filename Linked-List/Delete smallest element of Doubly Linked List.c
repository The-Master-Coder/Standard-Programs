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


struct dlinkedlist * delete_head(struct dlinkedlist * start)
{
	struct dlinkedlist * temp;
	temp = start;
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

int find_smallest(struct dlinkedlist * start)
{
	int min, c = 1, d = 1;
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		printf("List is Empty!!\n");
		return 0;
	}
	min = temp -> item;
	while (temp -> next != NULL) {
		if (temp -> next -> item < min) {
			min = temp -> next -> item;
			d = c + 1;
		}
		temp = temp -> next;
		c++;
	}
	return d;
}

int main()
{
	struct dlinkedlist* start;
	start = NULL;
	int choice;
	int value;
	int p, x;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Remove the xth node\n");    
		printf("3. Print all the nodes\n");
		printf("4. Delete the smallest node\n");
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
				printf("Enter the position of node which you want to delete:\n");
				scanf("%d", &p);
				start = delete_x(start,p);
				break;
			case 3:
				print_all(start);
				break ;
			case 4:
				x = find_smallest(start);
				if (x != 0) {
					start = delete_x(start,x);
					break;
				}
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid Choice!\n");
				break;
		}
	}
	return 0;
}
