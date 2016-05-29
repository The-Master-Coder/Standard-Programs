#include<stdio.h>
#include<string.h>
#define d 256
void search(char txt[], char pat[], int q)
{
	int l1, l2, h, p, t, i, j;
	p = t = 0;
	h = 1;
	l1 = strlen(txt);
	l2 = strlen(pat);
	for(i = 0; i < l2 - 1; i++) {
		h = (h * d) % q;
	}
	
	for(i = 0; i < l2; i++) {
		p = (d*p + pat[i]) % q;
		t = (d*t + txt[i]) % q;
	}
	
	for(i = 0; i <= l1 - l2; i++) {
		if (p == t) {
			for (j = 0; j < l2; j++) {
            	if (txt[i + j] != pat[j]) {
            		break;
				}
			}
    		if (j == l2) {
          	 printf("Pattern found at index %d\n", i);
       		}
		}
		if (i < (l1 - l2)) {
			t = (d*(t - txt[i] * h) + txt[i + l2]) % q;
			if (t < 0) {
				t = t + q;
			}
		}
	}
}

int main()
{
	int q;
	q = 101;
	char txt[100];
	char pat[100];
	gets(txt);
	gets(pat);
	search(txt,pat,q);
	return 0;
}
