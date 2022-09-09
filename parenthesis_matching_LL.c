#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node* next;
}*top = NULL;

void push(char x)
{
	struct node* t;
	t = (struct node*)malloc(sizeof(struct node));

	if (t == NULL)
		printf("Stack Overflow\n");
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

char pop()
{
	char x = -1;
	if (top == NULL)
		printf("Stack Underflow\n");
	else
	{
		struct node* t;
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void display()
{
	struct node* p;
	p = top;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

int isBalanced(char* exp)
{
	int i;
	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == ')')
		{
			if (top == NULL)
				return 0;
			else
				pop();
		}
	}
	if (top == NULL)
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