#include<stdio.h>
#include<stdlib.h>
#define size 11

struct employee {
	char name[20];
	int age;
	int id;	
};

struct record {
	struct employee info;
	struct record *next;
};

void insert(struct employee emprec, struct record *table[])
{
	int h, key;
	struct record *temp;
	key = emprec.id;
	h = key % size;
	
	temp = (struct record *) malloc(sizeof(struct record));
	temp->info = emprec;
	temp->next = table[h];
	table[h] = temp;
}

int search(int key, struct record *table[])
{
	int h;
	struct record *temp;
	h = key % size;
	temp = table[h];
	while (temp != NULL) {
		if (temp->info.id == key) {
			return h;
		}
		temp = temp->next;
	}
	return -1;
}

void delete(int key, struct record *table[])
{
	int h;
	struct record *temp1, *temp2;
	h = key % size;
	if (table[h] == NULL) {
		printf("Key %d not found\n",key);
		return;
	} else if (table[h]->info.id == key) {
		temp1 = table[h];
		table[h] = table[h]->next;
		free(temp1);
		return;
	}
	temp2 = table[h];
	
	while (temp2->next != NULL) {
		if (temp2->next->info.id == key) {
			temp1 = temp2->next;
			temp2->next = temp1->next;
			free(temp1);
			return;
		}
		temp2 = temp2->next;
	}
	printf("Key %d not found\n",key);
}

void display(struct record *table[])
{
	int i;
	struct record *temp;
	for (i = 0; i < size; i++) {
		printf("[%d] :\n",i);
		if (table[i] != NULL) {
			temp = table[i];
			while (temp != NULL) {
				printf("%s %d %d\n",temp->info.name, temp->info.age, temp->info.id);
				temp = temp->next;
			}
		}
		printf("\n");
	}
}

int main()
{
	struct record *table[size];
	struct employee emprec;
	int i, x, n, key, choice;
	for(i = 0; i < size; i++) {
		table[i] = NULL;
	}
	while (1) {
		printf("1. Insert a record\n");
		printf("2. Delete a record\n");
		printf("3. Search a record\n");
		printf("4. Display the hash table\n");
		printf("5. Exit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the record\n");
				scanf("%s %d %d", emprec.name, &emprec.age, &emprec.id);
				insert(emprec,table);
				break;
				
			case 2:
				printf("Enter the key to be deleted\n");
				scanf("%d", &key);
				delete(key,table);
				break;
				
			case 3:
				printf("Enter a key to be searched\n");
				scanf("%d", &key);
				x = search(key,table);
				if (x == -1) {
					printf("Key not found\n");
				} else {
					printf("Key found in chain %d\n", x);
				}
				break;
				
			case 4:
				display(table);
				break;
				
			case 5:
				exit(1);
		}
	}
	return 0;
}
