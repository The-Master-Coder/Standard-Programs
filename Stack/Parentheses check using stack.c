#include<stdio.h>
#include<string.h>

int are_pair(char opening,char closing)
{
	if (opening == '(' && closing == ')') {
		return 1;
	} else if (opening == '{' && closing == '}') {
		return 1;
	} else if (opening == '[' && closing == ']') {
		return 1;
	}
	return 0;
}

int push(char item,char *ptr,int top,int l)
{
	if (top == (l - 1)) {
		printf("Stack Overflow\n\n");
		return;
	}	
	top = top + 1;
	ptr[top] = item;
	return top;
}

int pop(int top)
{
	if (top == -1) {
		printf("Stack Underflow\n\n");
		return -1;
	} else {
		top = top - 1;
		return top;
	}
}


int check_balanced_parentheses(char *ptr,int l)
{
	int i, top = -1;
	
	char stack[l];
	for(i = 0; i < l; i++) {
		if (ptr[i] == '(' || ptr[i] == '[' || ptr[i] == '{') {
			top = push(ptr[i],stack,top,l);
		} else if (ptr[i] == ')' || ptr[i] == ']' || ptr[i] == '}') {
			if (top == -1 ||  !are_pair(stack[top],ptr[i])) {
				return 0;
			} else {
				top = pop(top);
			}
		}
	}
	if (top == -1) {
		return 1;
	} else {
		return 0;
	}	
}

int main()
{
	char s[100];
	gets(s);
	int t, l;
	l = strlen(s);
	t = check_balanced_parentheses(s,l);
	if (t == 1) {
		printf("Parentheses are balanced\n");
	} else {
		printf("Parentheses are not balanced\n");
	}
	return 0;
}
