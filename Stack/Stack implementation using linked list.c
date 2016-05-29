#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;

void push(int item)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	if (tmp == NULL) {
		printf("Stack Overflow\n");
		return;
	}
	tmp -> data = item;
	tmp -> next = head;
	head = tmp;
}

int pop()
{
	struct node *tmp;
	int item;
	if (is_empty()) {
		printf("Stack Underflow\n");
		return;
	}
	tmp = head;
	item = tmp -> data;
	head = head -> next;
	free(tmp);
	printf("Popped item is : %d\n\n", item);
	return;
}

int top()
{
	if (is_empty()) {
		printf("Stack Underflow\n");
		return 0;
	}
	printf("Item at the top is %d\n\n", head -> data);
}

int is_empty()
{
	if (head == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int size()
{
	int count = 0;
	struct node *tmp;
	tmp = head;
	if (is_empty()) {
		printf("Stack is empty\n\n");
		return ;
	}
	while (tmp != NULL) {
		count++;
		tmp = tmp -> next;
	}
	printf("%d\n\n", count);
}

int main()
{
	int choice, item;
	
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
				push(item);
				break;
			case 2 :
				pop();
				break;
			case 3 :
				top();
				break;
			case 4 :
				size();
				break;
			case 5 :
				exit(1);
			default:
				printf("Invalid choice\n\n");
		}
	}
	return 0;
}
