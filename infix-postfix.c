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

int isFull(struct stack st)
{
	if (st.top == st.size - 1)
		return 1;
	else
		return 0;
}

int isEmpty(struct stack st)
{
	if (st.top == -1)
		return 1;
	else
		return 0;
}

char stackTop(struct stack st)
{
	if (!isEmpty(st))
		return st.S[st.top];
	return -1;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

int pre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	else
		return 0;
}

char* InToPost(char* infix)
{
	int i = 0, j = 0;

	struct stack st;
	st.size = strlen(infix);
	st.top = -1;
	st.S = (char*)malloc(st.size * sizeof(char));

	char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (pre(infix[i]) > pre(stackTop(st)))
				push(&st, infix[i++]);
			else
				postfix[j++] = pop(&st);
		}
	}
	while (!isEmpty(st))
	{
		postfix[j++] = pop(&st);
	}
	postfix[j] = '\0';
	return postfix;
}

int main()
{
	char* infix = "a+b*c-d/e";
	char* postfix;
	postfix = InToPost(infix);
	printf("%s ", postfix);
	return 0;
}