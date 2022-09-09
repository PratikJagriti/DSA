#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int* S;
};

void create(struct stack* st)
{
	printf("Enter the size of the stack:");
	scanf_s("%d",&st->size);
	st->top = -1;
	st->S = (int*)malloc(st->size * sizeof(int));
}

void push(struct stack* st, int x)
{
	if (st->top == st->size-1)
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

int peek(struct stack st, int index)
{
	int x = -1;
	if (st.top - index + 1 < 0)
		return x;
	else
	{
		x = st.S[st.top - index + 1];
		return x;
	}
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


int main()
{
	struct stack st;
	create(&st);
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	display(st);
	printf("%d\n", peek(st, 3));
	printf("%d\n", isFull(st));
	printf("%d\n", isEmpty(st));
	printf("%d\n", stackTop(st));
}