#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 25

char s[MAX_SIZE];
int top = -1;

void main()
{
	char infix[25], postfix[25];
	int i = 0, j = 0;

	int PRIORITY(char x);
	void PUSH(char x);
	char POP();

	PUSH('#');

	printf("Enter a valid infix expression\n");
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
				postfix[j++] = POP();
			PUSH(infix[i]);
		}
		else
		{
			printf("invalid operator\n");
			exit(0);
		}
		i++;
	}

	while (s[top] != '#')
		postfix[j++] = POP();

	postfix[j] = '\0';

	printf("The infix expression %s converted to postfix is : %s", infix, postfix);
}

int PRIORITY(char x)
{
	if (x == '#' || x == '(')
		return 1;
	else if (x == '+' || x == '-')
		return 2;
	else if (x == '*' || x == '/')
		return 3;
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
		printf("Stack underflow\n");
	else
	{
		return s[top--];
	}
}