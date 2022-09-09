#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node* next;
}*top = NULL;

void push(int x)
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

int pop()
{
	int x = -1;
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
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int Stacktop()
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

int PostfixEval(char* postfix)
{
	int i, x1, x2, r;

	for (i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
			push(postfix[i] - '0');
		else
		{
			x2 = pop();
			x1 = pop();
			switch (postfix[i])
			{
			case'+':r = x1 + x2; break;
			case'-':r = x1 - x2; break;
			case'*':r = x1 * x2; break;
			case'/':r = x1 / x2; break;
			}
			push(r);
		}
	}
	return pop();
}

int main()
{
	char* postfix = "34*2+82/-";
	printf("The result is %d\n", PostfixEval(postfix));
}