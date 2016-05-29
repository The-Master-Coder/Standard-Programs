#include <stdio.h>
#include<stdlib.h>

struct stack {
	unsigned int size;
	int data[100];
};

int push(int item,int *ptr,unsigned int *size)
{
	if (is_full(size)) {
		printf("Stack Overflow\n");
		return;
	}	
	ptr[*size] = item;
	printf("%d\n", ptr[*size]);
	*size = *size + 1;
}

int is_full(unsigned int *size)
{
	
	if (*size == 100){
		return 1;
	} else {
		return 0;
	}
}


int is_empty(unsigned int *size)
{
	if (*size == 0) {
		return 1;
	} else {
		return 0;
	}
}


int top(int *ptr,unsigned int *size)
{
	if (is_empty(size)) {
		printf("Stack Underflow\n");
		return;
	} else {
		printf("%d\n", ptr[*size - 1]);
	}
}

int pop(int *ptr,unsigned int *size)
{
	unsigned int temp;
	if (is_empty(size)) {
		printf("Stack Underflow\n");
		return;
	} else {
		temp = *size - 1;
		*size = *size - 1;
		return ptr[temp];
	}
}

int size_of_stack(unsigned int *size)
{
	if (is_empty(size)) {
		printf("Stack is empty\n");
		return ;
	}
	printf("%d\n", *size);
}

int main()
{
	struct stack s1;
	s1.size = 0;
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
				push(item,s1.data,&s1.size);
			
				break;
			case 2 :
				x = pop(s1.data,&s1.size);
				if (x != 0) {
					printf("%d\n\n", x);
				}
				break;
			case 3 :
				top(s1.data,&s1.size);
				break;
			case 4 :
				size_of_stack(&s1.size);
				break;
			case 5 :
				exit(1);
			default:
				printf("Invalid choice\n\n");
		}
	}
	return 0;
}

