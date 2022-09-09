#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 25

int s[MAX_SIZE];
int top = -1;

void main()
{
	char postfix[25];
	int i = 0;
	int op1, op2, op3;

	void PUSH(int);
	int POP();

	printf("enter a valid postfix expression\n");
	gets(postfix);

	while (postfix[i] != '\0')
	{
		if (isdigit(postfix[i]))
			PUSH(postfix[i]-'0');
		else
		{
			op2 = POP();
			op1 = POP();

			switch(postfix[i])
			{
			case '+': op3 = op1 + op2;
				break;
			case '-': op3 = op1 - op2;
				break;
			case '*': op3 = op1 * op2;
				break;
			case '/': op3 = op1 / op2;
				break;
			default: printf("invalid operator %c", postfix[i]);
				exit(0);
			}
			PUSH(op3);
		}
		i++;
	}

	if (top > 0)
		printf("\ninappropriate postfix expression\n");
	else
		printf("\nthe evaluation of the postfix expression %s is %d", postfix, s[top]);
}

void PUSH(int x)
{
	if (top >= MAX_SIZE - 1)
	{
		printf("stack overflow\n");
		exit(0);
	}
	else
	{
		top++;
		s[top] = x;
	}
}

int POP()
{
	if (top == -1)
	{
		printf("stack underflow\n");
		exit(0);
	}
	else
		return s[top--];
}