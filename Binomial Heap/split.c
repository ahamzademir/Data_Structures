#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "P1     3     0 P2     1     2 P3     20    3 P4     12    5 P5     4     6 P6     6     7 P7     10    8 P8     14    9 P9     12    10 P10    7     11 P11    6     12 P12    8     13 P13    10    15 P14    11    17 P15    12    18 P16    1     19 P17    25    20 P18    10    21 P19    5     22 P20    8     25";
	int init_size = strlen(str);
	char delim[] = "P";
	char space[] = " ";
	char str2[] = "";

	char *ptr = strtok(str, delim);
	
	
	while(ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}
	int i;
	int j;
	/* This loop will show that there are zeroes in the str after tokenizing */
	for (i = 0; i < init_size; i++)
	{
		str2=str[i];
		printf("%d ", str[i]); 
		char *p = strtok(str2[], space);
		for(j=0; j < 3; j++){
	
			char *p = strtok(str[], space);
			printf("%d ", str[j]);
	
		}
	
			
	}
	
	printf("\n");
	
	return 0;
}
