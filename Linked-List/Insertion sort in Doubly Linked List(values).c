#include<stdio.h>

struct node
{
	int item;
	struct node * next;
	struct node * prev;
};

int main()
{
  	struct node n1, n2, n3, n4, n5;
  	struct node *start, *temp, *temp1, *temp2, *temp3;
  	int value;
  	start = &n1;
  	n1.item = 7;
  	n1.prev = NULL;
  	n1.next = &n2;
  	n2.item = 5;
  	n2.prev = &n1;
  	n2.next = &n3;
  	n3.item = 2;
  	n3.prev = &n2;
  	n3.next = &n4;
  	n4.item = 3;
  	n4.prev = &n3;
  	n4.next = &n5;
  	n5.item = 1;
  	n5.prev = &n4;
  	n5.next = NULL;
  	
  	temp3 = start;
	while(temp3 != NULL) {
		printf("%d ", temp3 -> item);
		temp3 = temp3 -> next;
	}
	printf("\n");

  	temp = start;
  	temp = temp -> next;
  	temp1 = temp -> prev;
  	temp2 = temp;
  	
	while (temp != NULL) {
  		value = temp -> item;
  		while (temp1 != NULL && temp1 -> item > value) {
			temp2 -> item = temp1 -> item;
			temp2 = temp2 -> prev;
			temp1 = temp1 -> prev;
		}
		temp2 -> item = value;
		if (temp -> next == NULL) {
			temp3 = start;
			while(temp3 != NULL) {
				printf("%d ", temp3 -> item);
				temp3 = temp3 -> next;
			}
			printf("\n");
			return 0;
		}
		temp = temp -> next;
		temp1 = temp -> prev;
		temp2 = temp;
	}
  	return 1;
}
