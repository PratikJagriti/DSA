#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*top=NULL;

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

int peek(int pos)
{
	struct node* p;
	p = top;
	int i;

	for (i = 0; i < pos - 1 && p != NULL; i++)
		p = p->next;
	if (p != NULL)
		return p->data;
	else
		return -1;
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

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	printf("Element deleted is: %d\n",pop());
	printf("%d\n", peek(2));
	printf("%d\n", Stacktop());
	printf("%d\n", isFull());
	printf("%d\n", isEmpty());
	display();
}