#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	int size;
	int top;
	char* S;
};

void push(struct stack* st, char x)
{
	if (st->top == st->size - 1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

char pop(struct stack* st)
{
	char x = -1;
	if (st->top == -1)
		printf("Stack Underflow\n");
	else
		x = st->S[st->top--];
	return x;
}

void display(struct stack st)
{
	int i;
	for (i = st.top; i >= 0; i--)
		printf("%c ", st.S[i]);
	printf("\n");
}

int isBalanced(char* exp)
{
	int i;
	struct stack st;
	st.size = strlen(exp);
	st.top = -1;
	st.S = (char*)malloc(st.size * sizeof(char));

	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			push(&st, exp[i]);
		else if (exp[i] == ')')
		{
			if (st.top == -1)
				return 0;
			else
				pop(&st);
		}
	}
	if (st.top == -1)
		return 1;
	else
		return 0;
}

int main()
{
	char* exp = "((a+b)*(c-d))";
	printf("%d\n", isBalanced(exp));
	return 0;
}