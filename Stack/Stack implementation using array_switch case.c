#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void push(int *ptr,int item,int *head)
{
	if (is_full(ptr,head)) {
		printf("Stack Overflow\n\n");
		return;
	}	
	*head = *head + 1;
	ptr[*head] = item;
	printf("%d\n\n", ptr[*head]);
	return;
}

int is_full(int *ptr,int *head)
{
	
	if (*head == (MAX-1)){
		return 1;
	} else {
		return 0;
	}
}


int is_empty(int *head)
{
	if (*head == -1) {
		return 1;
	} else {
		return 0;
	}
}


int top(int *ptr, int *head)
{
	if (is_empty(head)) {
		printf("Stack Underflow\n\n");
		return;
	} else {
		printf("%d\n\n", ptr[*head]);
	}
}

int pop(int *ptr, int *head)
{
	int temp;
	if (is_empty(head)) {
		printf("Stack Underflow\n");
		return;
	} else {
		temp = *head;
		*head = *head - 1;
		return ptr[temp];
	}
}

int size(int *head)
{
	int i;
	int count = 0;
	if (is_empty(head)) {
		printf("Stack is empty\n\n");
		return ;
	}
	for(i = *head; i >= 0; i--) {
		count++;
	}
	printf("%d\n\n", count);
}

int main()
{
	int head = -1;
	int stack_arr[MAX];
	int choice, item, x;
	
	while(1) {
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display the top element\n");
		printf("4. Display size of Stack\n");
		printf("5. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1 :
				printf("Enter the item to be pushed : ");
				scanf("%d", &item);
				push(stack_arr,item,&head);
				break;
			case 2 :
				x = pop(stack_arr,&head);
				if (x != 0) {
					printf("%d\n\n", x);
				}
				break;
			case 3 :
				top(stack_arr,&head);
				break;
			case 4 :
				size(&head);
				break;
			case 5 :
				exit(0);
			default:
				printf("Invalid choice\n\n");
		}
	}
	return 0;
}
