#include<stdio.h>
#include<ctype.h>

char st[25],x;
int top = -1;

void main()
{
	char infix[25], postfix[25];
	int i = 0, j = 0;
	char x;
	int PRIORITY(char x);
	void PUSH(char x);
	char POP();

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
			while (st[top] != '(')
				postfix[j++] = POP();
			POP();
		}
		else if (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
		{
			while (PRIORITY(infix[i]) <= PRIORITY(st[top]))
			{
				postfix[j++] = POP();
			}
			PUSH(infix[i]);
		}
		else
		{
			printf("invalid operator");
			exit(0);
		}
		i++;
	}

	while (st[top] != '#')
		postfix[j++] = POP();

	postfix[j] = '\0';

	printf("%s infix expression converted to postfix is %s", infix, postfix);
}

void PUSH(char x)
{
	if (top >= 24)
		printf("\nstack overflow\n");
	else
	{
		top++;
		st[top] = x;
	}
}

char POP()
{
	if (top == -1)
	{
		printf("\nstack underflow\n");
		exit(0);
	}
	else
	{
		return st[top--];
	}
}

int PRIORITY(char x)
{
	if (x == '(' || x == '#')
		return 1;
	else if (x == '+' || x == '-')
		return 2;
	else if (x == '*' || x == '/')
		return 3;
}