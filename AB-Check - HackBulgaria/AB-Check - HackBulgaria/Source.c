#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum BOOL {True = 1, False = 0} BOOL;
typedef enum STATE {String, A, Char1, Char2, B} STATE;

STATE Find(char ch, STATE state);
BOOL KMP(char str[]);

int main()
{
	char str[100];
	BOOL result;

	printf("Input your string!\n");
	fgets(str, 99, stdin);

	result = KMP(str);
	if (result == True)
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

BOOL KMP(char str[])
{
	char *pt = str;
	STATE state = String;

	while(*pt !='\0')
	{
		state = Find(*pt, state);
		if(state == B)
		{
			return True;
		}
		pt++;
	}
	return False;
}

STATE Find(char ch, STATE state)
{
	switch(state)
	{
		case String:
			if(ch == 'a')
			{
				state = A;
			}
			break;
		case A:
			if(ch != 'b')
			{
				state = Char1;
			}
			else
			{
				state = String;
			}
			break;
		case Char1:
			if(ch !='b')
			{
				state = Char2;
			}
			else
			{
				state = String;
			}
			break;
		case Char2:
			if(ch == 'b')
			{
				state = B;
			}
			else if(ch == 'a')
			{
				state = A;
			}		
			else 
			{
				state = String;
			}
			break;		
	}
	return state;
}