#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 25

char s[MAX_SIZE],postfix[MAX_SIZE];
int op1, op2, op3;
int i = 0, top = -1;

void main()
{
	void PUSH(int x);
	int POP();

	printf("\nenter the postfix expression to be evaluated: ");
	gets(postfix);

	while (postfix[i] != '\0')
	{
		if (isdigit(postfix[i]))
			PUSH(postfix[i]-'0');
		else
		{
			op2 = POP();
			op1 = POP();

			switch (postfix[i])
			{
			case '+': op3 = op1 + op2;
				break;
			case '-': op3 = op1 - op2;
				break;
			case '*': op3 = op1 * op2;
				break;
			case '/': op3 = op1 / op2;
				break;
			default:
			{
				printf("invalid operatop %c", postfix[i]);
				exit(0);
			}
			}
			PUSH(op3);
		}
		i++;
	}

	if (top > 0)
	{
		printf("invalid postfix expression\n");
		exit(0);
	}
	else
	{
		printf("evaluation of the given postfix expression %s is: %d", postfix, s[top]);
	}
}

void PUSH(int x)
{
	if (top >= MAX_SIZE - 1)
		printf("stack overflow\n");
	else
	{
		top++;
		s[top] = x;
	}
}

int POP()
{
	if (top == -1)
		printf("stack underflow\n");
	else
	{
		return s[top--];
	}
}