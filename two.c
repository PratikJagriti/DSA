#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 25

char s[MAX_SIZE];
int top = -1;

void main()
{
	char infix[25], postfix[25];
	int i = 0, j = 0;

	void PUSH(char x);
	char POP();
	int PRIORITY(char x);

	PUSH('#');

	printf("\nenter a valid infix expression\n");
	gets(infix);

	while (infix[i] != '\0')
	{
		if (isalnum(infix[i]))
			postfix[j++] = infix[i];
		else if (infix[i] == '(')
			PUSH(infix[i]);
		else if (infix[i] == ')')
		{
			while (s[top] != '(')
				postfix[j++] = POP();
			POP();
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			while (PRIORITY(s[top]) >= PRIORITY(infix[i]))
			{
				postfix[j++] = POP();
			}
			PUSH(infix[i]);
		}
		else
		{
			printf("\ninvalid symbol %c\n", infix[i]);
			exit(0);
		}
		i++;
	}

	while(s[top]!='#')
	{
		postfix[j++] = POP();
	}
	postfix[j] = '\0';

	printf("\nthe infix expression %s converted to postfix is %s\n", infix, postfix);

}

void PUSH(char x)
{
	if (top >= MAX_SIZE)
		printf("stack overflow\n");
	else
	{
		top++;
		s[top] = x;
	}
}

char POP()
{
	if (top == -1)
		printf("stack underflow\n");
	else
	{
		return s[top--];
	}
}

int PRIORITY(char x)
{
	int i;
	if (x == '#' || x == '(')
		return 1;
	else if (x == '+' || x == '-')
		return 2;
	else if (x == '*' || x == '/')
		return 3;
}