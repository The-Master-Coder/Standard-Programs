#include<stdio.h>
#include<string.h>
 
void search(char txt[], char pat[])
{
    int l1, l2, i, j;
	l1 = strlen(txt);
	l2 = strlen(pat);
  
    for (i = 0; i <= l1 - l2; i++) {
    	for (j = 0; j < l2; j++) {
            if (txt[i + j] != pat[j]) {
            	break;
			}
		}
    	if (j == l2) {
           printf("Pattern found at index %d \n", i);
       	}
	}
}

int main()
{
   char txt[100];
   char pat[100];
   scanf("%s", txt);
   scanf("%s", pat);
   search(txt,pat);
   return 0;
}
