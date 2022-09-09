#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 4

char s[MAX_SIZE];
int top = -1;

int main()
{
	char infix[25], postfix[25];
	int i = 0, j = 0;
	int ch;
	char x;

	void PUSH(char x);
	char POP();
	int PRIORITY(char x);

	PUSH('#');

	printf("Enter the infix expression to be converted:");
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
			printf("Invalid character %c", infix[i]);
			exit(0);
		}
		i++;
	}

	while (s[top] != '#')
	{
		postfix[j++] = POP();
	}
	postfix[j] = '\0';

	printf("The given infix expression %s converted to postfix is %s", infix, postfix);
	
}

void PUSH(char x)
{
	if (top >= MAX_SIZE - 1)
	{
		printf("stack full");
		exit(0);
	}
	else
		s[++top] = x;
}

char POP()
{
	if (top == -1)
	{
		printf("Stack empty");
		exit(0);
	}
	else
		return s[top--];
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