#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *next;
	struct node *prev;
};

int main()
{
	int i, n, value;
	printf("How many numbers do you want in your DLL?\n");
	scanf("%d", &n);
	printf("Enter the values of the nodes:\n");
	struct node *start;
	start = NULL;
	struct node *temp1;
	
	for(i = 0; i < n; i++) {
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &value);
		temp -> item = value;
		temp -> next = NULL;
		if (start == NULL) {
			temp -> prev = NULL;
			start = temp;
			continue;
		}
		temp1 = start;
		while (temp1 -> next != NULL) {
			temp1 = temp1 -> next;
		}
		temp1 ->next = temp;
		temp -> prev = temp1;
	}
	// BELOW IS PRINT OPERATION
	temp1 = start;
	if (temp1 == NULL) {
		printf("List is Empty!!\n");
		return 1;
	}
	while (temp1 != NULL) {
		printf("%d ", temp1 -> item);
		temp1 = temp1 -> next;
	}
	printf("\n");
	// BELOW IS REVERSE PRINT OPERATION
	temp1 = start;
	if (temp1 == NULL) {
		printf("List is Empty!!\n");
		return 1;
	}
	while(temp1 -> next != NULL) {
		temp1 = temp1 -> next;
	}
	while(temp1 != NULL) {
		printf("%d ", temp1 -> item);
		temp1 = temp1 -> prev;
	}
	printf("\n");
	
	return 0;
}
