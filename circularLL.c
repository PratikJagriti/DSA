#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*head;

void create(int A[], int n)
{
	int i;
	struct node* last, * t;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = A[0];
	head->next = head;
	last = head;

	for (i = 1; i < n; i++)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

void display(struct node* h)
{
	do
	{
		printf("%d ", h->data);
		h = h->next;
	} while (h != head);
}

void Rdisplay(struct node* h)
{
	static int flag = 0;
	if (h != head || flag == 0)
	{
		flag = 1;
		printf("%d ", h->data);
		Rdisplay(h->next);
	}
}

int length(struct node* p)
{
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != head);
	return len;
}

void insert(struct node* p, int index, int x)
{
	if (index<0 || index>length(p))
		return;
	struct node* t;
	int i;

	if (index == 0)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		if (head == NULL)
		{
			head = t;
			head->next = head;
		}
		else
		{
			while (p->next != head)
				p = p->next;
			p->next = t;
			t->next = head;
			head = t;
		}
	}
	else
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

int Delete(struct node* p, int index)
{
	struct node* q;
	int i, x;

	if (index<1 || index>length(head))
		return -1;

	if (index == 1)
	{
		while (p->next != head)
			p = p->next;
		x = head->data;
		if (p == head)
		{
			free(head);
			head = NULL;
		}
		else
		{
			p->next = head->next;
			free(head);
			head = p->next;
		}
	}
	else
	{
		for (i = 0; i < index - 2; i++)
			p = p->next;
		q = p->next;
		x = q->data;
		p->next = q->next;
		free(q);
	}
	return x;
}

int main()
{
	int A[] = { 10,20,30,40,50 };
	create(A, 5);
	insert(head, 2, 55);
	Rdisplay(head);
	printf("\n");
	printf("Deleted element:%d\n",Delete(head, 3));
	display(head);
}