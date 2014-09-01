#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DashInsert(int num);

int main()
{
	int num;
	int i;

	printf("Insert a number:\n");
	scanf("%d", &num);
	fflush(stdin);
	DashInsert(num);

	system("pause");
	return 0;
}

void DashInsert(int num)
{
	int i, j, integer[2];
	char oldstr[16];
	char newstr[31];

	sprintf(oldstr,"%d", num);

	for(i=0,j=0; i<strlen(oldstr); i++)
	{
		integer[0] = oldstr[i] - '0';
		integer[1] = oldstr[i+1] - '0';
		if(integer[0] % 2 != 0 && integer[1] % 2 != 0)
		{
			newstr[j] = oldstr[i];
			newstr[j+1] = '-';
			newstr[j+2] = oldstr[i+1];

			j+=2;
		}
		else
		{
			newstr[j] = oldstr[i];
			newstr[j+1] = oldstr[j+1];
			j++;
		}
	}
	newstr[j] = '\0';

	printf("\nBefore: ");
	puts(oldstr);
	printf("\nAfter: ");	
	puts(newstr);
}