#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	int size;
	int top;
	int* S;
};

void push(struct stack* st, int x)
{
	if (st->top == st->size - 1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

int pop(struct stack* st)
{
	int x = -1;
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
		printf("%d ", st.S[i]);
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

int stackTop(struct stack st)
{
	if (!isEmpty(st))
		return st.S[st.top];
	return -1;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
		return 0;
	else
		return 1;
}

int PostfixEval(char* postfix)
{
	int i, x1, x2, r;
	struct stack st;
	st.size = strlen(postfix);
	st.top = -1;
	st.S = (int*)malloc(st.size * sizeof(int));

	for (i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
			push(&st, postfix[i] - '0');
		else
		{
			x2 = pop(&st);
			x1 = pop(&st);
			switch (postfix[i])
			{
			case'+':r = x1 + x2; break;
			case'-':r = x1 - x2; break;
			case'*':r = x1 * x2; break;
			case'/':r = x1 / x2; break;
			}
			push(&st, r);
		}
	}
	return pop(&st);
}

int main()
{
	char* postfix = "35*62/+4-";
	printf("The result is %d\n", PostfixEval(postfix));
}