#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* prev;
	int data;
	struct node* next;
}*first=NULL;

void create(int A[], int n)
{
	struct node* t, * last;
	int i;

	first = (struct node*)malloc(sizeof(struct node));
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t= (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}

void display(struct node* p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int length(struct node* p)
{
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

void insert(struct node* p, int index, int x)
{
	struct node* t;
	int i;

	if (index<0 || index>length(p))
		return;

	if (index == 0)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next)
			p->next->prev = t;
		p->next = t;
	}
}

int Delete(struct node* p, int index)
{
	int x = -1, i;

	if (index<1 || index>length(p))
		return x;

	if (index == 1)
	{
		first = first->next;
		if (first)
			first->prev = NULL;
		x = p->data;
		free(p);
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		p->prev->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
		x = p->data;
		free(p);
	}
	return x;
}

int main()
{
	int A[] = { 10,20,30,40,50 };
	create(A, 5);
	display(first);
	printf("\nLength=%d\n", length(first));
	insert(first, 2, 25);
	display(first);
	printf("\n");
	printf("Deleted element: %d\n", Delete(first, 3));
	display(first);
	printf("\n");
}