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

int smallest(struct dlinkedlist* start)
{
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		return 0;
	}
	int min = temp -> item;
	temp = temp -> next;
	while (temp != NULL) {
		if (temp -> item < min) {
			min = temp -> item;
		}
		temp = temp -> next;
	}
	return min;
}

int largest(struct dlinkedlist* start)
{
	struct dlinkedlist * temp;
	temp = start;
	if (temp == NULL) {
		return 0;
	}
	int max = temp -> item;
	temp = temp -> next;
	while (temp != NULL) {
		if (temp -> item > max) {
			max = temp -> item;
		}
		temp = temp -> next;
	}
	return max;
}

int difference(struct dlinkedlist* start)
{
	int s, l, d;
	s = smallest(start);
	l = largest(start);
	d = l - s;
	return d;
}

int main()
{
	struct dlinkedlist* start;
	start = NULL;
	int choice;
	int value;
	int p, s, l, d;
	while(1) {
		printf("Choices:\n");
		printf("1. Insert at beginning\n");
		printf("2. Print all the nodes\n");
		printf("3. Print Smallest\n");
		printf("4. Print largest\n");
		printf("5. Print largest - smallest\n");
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
				print_all(start);
				break ;
			case 3:
				s = smallest(start);
				if (s != 0) {
					printf("%d\n", s);
					break;
				}
				printf("List is Empty!!\n");
				break;
			case 4:
				l = largest(start);
				if (l != 0) {
					printf("%d\n", l);
					break;
				}
				printf("List is Empty!!\n");
				break;
			case 5:
				d = difference(start);
				if (d != 0) {
					printf("%d\n", d);
					break;
				}
				printf("List is Empty!!\n");
				break;
			case 6:
				exit(1);
			default:
				printf("Invalid Choice!\n");
				break;
		}
	}
	return 0;
}

