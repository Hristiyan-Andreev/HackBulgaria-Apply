#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum BOOL {True = 1, False = 0} BOOL;
BOOL ExOh(char str[]);

int main ()
{
	char str[100];
	BOOL result = True;

	printf("Input your string, only lowercase o`s and x`s !\n");
	fgets(str, 99, stdin);
	result = ExOh(str);
	if(result == True)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	

	system("pause");
	return 0;
}

BOOL ExOh(char str[])
{
	int sum = 0, i;

	for(i=0; i < strlen(str)-1; i++)
	{
		if(str[i] == 'x')
		{ 
			sum++;
		}
		else
		{
			sum--;
		}
	}

	if(sum == 0)
		return True;
	else
		return False;
}