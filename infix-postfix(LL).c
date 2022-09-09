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

char Stacktop()
{
	if (top == NULL)
		return -1;
	else
		return top->data;
}

int isFull()
{
	struct node* t;
	t = (struct node*)malloc(sizeof(struct node));

	int r = t ? 0 : 1;
	free(t);
	return r;
}

int isEmpty()
{
	return top ? 0 : 1;
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
	else if (x == '*' || x == '/')
		return 2;
	else
		return 0;
}

char* InToPost(char* infix)
{
	int i = 0, j = 0;

	char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (pre(infix[i]) > pre(Stacktop()))
				push(infix[i++]);
			else
				postfix[j++] = pop();
		}
	}
	while (!isEmpty())
	{
		postfix[j++] = pop();
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