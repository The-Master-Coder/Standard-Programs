#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void insertAtTheBegin(struct node **start, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *start;
    *start = temp;
}
 
void printList(struct node *start)
{
    struct node *temp = start;
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *node;
    struct node *end = NULL;
 
    if (start == NULL)
        return;

    while(1) {
    	swapped = 0;
        node = start;
 
        while (node->next != end)
        {
            if (node->data > node->next->data)
            { 
                swap(node, node->next);
                swapped = 1;
            }
            node = node->next;
        }
        end = node;
        if (swapped == 0) {
        	break;
        }
    }
}

int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;
 
    struct node *start = NULL;

    for (i = 0; i < 6; i++) {
        insertAtTheBegin(&start, arr[i]);
    }

    printf("Linked list before sorting:\n");
    printList(start);
 
    bubbleSort(start);

    printf("Linked list after sorting:\n");
    printList(start);

    return 0;
}