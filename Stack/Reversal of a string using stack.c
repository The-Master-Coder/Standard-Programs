#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

int push(char *ptr,int top,char item)
{
	if (top == SIZE-1) {
		printf("Stack Overflow\n");
		return;
	}
	top++;
	ptr[top] = item;
	return top;
}

char pop(char *ptr,int top)
{
	if (top == -1) {
		printf("Stack Underflow\n");
		return;
	}
	return ptr[top];
}

int main()
{
	char s[100];
	char stack[SIZE];
	gets(s);
	printf("Original String\n");
	puts(s);
	int l, i, top = -1;
	l = strlen(s);
	
	for(i = 0; i < l; i++) {
		top = push(stack,top,s[i]);
	}
	
	for(i = 0; i < l; i++) {
		s[i] = pop(stack,top);
		top--;
	}
	printf("Reversed String\n");
	puts(s);
	return 0;
}
