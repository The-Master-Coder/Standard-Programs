#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return 1;
	} else {
		return 0;
	}
}

int evaluate(char c, int operand1, int operand2)
{
	if (c == '+') {
		return operand1 + operand2;
	}else if (c == '-') {
		return operand1 - operand2;
	}else if (c == '*') {
		return operand1 * operand2;
	}else if (c == '/') {
		return operand1 / operand2;
	}	
}

int is_numeric_digit(char c)
{
	if (c >= '0' && c <= '9') {
		return 1;
	} else {
		return 0;
	}
}

int push(int item,int *ptr,int *top,int l)
{
	if (*top == (l - 1)) {
		printf("Stack Overflow\n\n");
		return;
	}	
	*top = *top + 1;
	ptr[*top] = item;
	return;
}

int pop(int *top)
{
	if (*top == -1) {
		printf("Stack Underflow\n\n");
		return;
	} else {
		*top = *top - 1;
		return;
	}
}

int main()
{
	char s[100];
	gets(s);
	int l, top = -1, a, b, i, result;
	l = strlen(s);
	int stack[l];
	
	for(i = l - 1; i >= 0; i--) {
		if (s[i] == ' ' || s[i] == ',') {
			continue;
		} else if (is_numeric_digit(s[i])) {
			int operand = 0; 
			while(i < l && is_numeric_digit(s[i])) {
			operand = (operand * 10) + (s[i] - '0'); 
			i++;
			}
			i--;
			push(operand,stack,&top,l);
		} else if (is_operator(s[i])) {
			a = stack[top];
			pop(&top);
			b = stack[top];
			pop(&top);
			result = evaluate(s[i], a, b);
			push(result,stack,&top,l);
		} else {
			printf("Expression is Invalid\n");
			exit(1);
		}
	}
	printf("%d\n" ,stack[top]);
	return 0;
}
