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
  	struct node *start, *a, *p, *q, * temp, *temp1, *temp2;
  	int value;
  	start = &n1;
  	n1.item = 7;
  	n1.prev = NULL;
  	n1.next = &n2;
  	n2.item = 21;
  	n2.prev = &n1;
  	n2.next = &n3;
  	n3.item = 3;
  	n3.prev = &n2;
  	n3.next = &n4;
  	n4.item = 5;
  	n4.prev = &n3;
  	n4.next = &n5;
  	n5.item = 1;
  	n5.prev = &n4;
  	n5.next = NULL;
  	
  	temp2 = start;
	while(temp2 != NULL) {
		printf("%d ", temp2 -> item);
		temp2 = temp2 -> next;
	}
	printf("\n");

  	a = start -> next;
  	p = q = start;
  	
	while (a != NULL) {
  		temp = a;
  		temp1 = a -> next;
		value = temp -> item;
  		while (q -> next != temp) {
			q = q -> next;
		}
		if (p -> item > value) {
			q -> next = q -> next -> next;
			if (q -> next != NULL) {
				q -> next -> prev = q;
			}
			temp -> next = p;
			p -> prev = temp;
			temp -> prev = NULL;
			start = temp;
		} else {
			while (p -> next != temp) {
				if (p -> next -> item > value) {
					q -> next = q -> next -> next;
					q -> next -> prev = q;
					temp -> next = p -> next;
					p -> next = temp;
					temp -> next -> prev = temp;
					temp -> prev = p;
					break;
				}
				p = p -> next;
			}
		}
		a = temp1;
		p = q = start;
	}
	temp2 = start;
	while(temp2 != NULL) {
		printf("%d ", temp2 -> item);
		temp2 = temp2 -> next;
	}
	printf("\n");
	return 0;
}
