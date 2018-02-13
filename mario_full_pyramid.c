#include <stdio.h>

int main(void) {
	int n;
	    
	char hash = '#';
	char space = ' ';
		  
	do {
		scanf("%d", &n);
	}
	while (n < 0 || n > 23);
		    
	for (int i = 0; i < n; i++) {
		// print left pyramid
		for (int j = 0; j < n; j++) {
			if (j < n - i - 1) {
				printf("%c", space);
			} else if (j >= n - i - 1) {
				printf("%c", hash);
			}
		}

		//print gap
		printf("  ");
				        
		// print right pyramid
		for (int j = 0; j < n; j++) {
			if (j <= i) {
				printf("%c", hash);
			} else if (j > i) {
				printf("%c", space);
			}
		}

		printf("\n");
					      
	}
	return 0;
}
