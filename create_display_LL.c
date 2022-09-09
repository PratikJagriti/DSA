#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*first = NULL, * second = NULL, * third = NULL;

void create(int A[], int n)
{
	int i;
	struct node* t, * last;
	first = (struct node*)malloc(sizeof(struct node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void create2(int A[], int n)
{
	int i;
	struct node* t, * last;
	second = (struct node*)malloc(sizeof(struct node));
	second->data = A[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < n; i++)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(struct node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
}

void Rdisplay(struct node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		Rdisplay(p->next);
	}
}

int length(struct node* p)
{
	int l = 0;
	while (p != NULL)
	{
		l++;
		p = p->next;
	}
	return l;
}

int Rlength(struct node* p)
{
	if (p != NULL)
		return Rlength(p->next) + 1;
	else
		return 0;
}

int add(struct node* p)
{
	int s = 0;
	while (p != 0)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}

int Radd(struct node* p)
{
	if (p != 0)
		return Radd(p->next) + p->data;
	else
		return 0;
}

int Max(struct node* p)
{
	int m = INT_MIN;
	while (p)
	{
		if (m < p->data)
			m = p->data;
		p = p->next;
	}
	return m;
}

int RMax(struct node* p)
{
	if (p == 0)
		return INT_MIN;
	else
	{
		int x = RMax(p->next);
		if (x > p->data)
			return x;
		else
			return p->data;
	}
}

struct node* search(struct node* p, int key)
{
	while (p)
	{
		if (p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
}

struct node* improvedsearch(struct node* p, int key)
{
	struct node* q=NULL;

	while (p)
	{
		if (p->data == key && q == NULL)
			return p;
		else if (p->data == key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

struct node* Rsearch(struct node* p, int key)
{

	if (p == NULL)
		return NULL;
	else
	{
		if (p->data == key)
			return p;
		else
			return Rsearch(p->next, key);
	}
}

void insert(struct node* p, int index, int x)
{
	if (index<0 || index>length(p))
		return;
	else
	{
		int i;
		struct node* t;
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		if (index == 0)
		{
			t->next = first;
			first = t;
		}
		else
		{
			for (i = 0; i < index - 1; i++)
				p = p->next;
			t->next = p->next;
			p->next = t;
		}
	}
}

void sortedinsert(struct node* p, int x)
{
	struct node* t, * q = NULL;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	t->next = NULL;

	if (first == NULL)
		first = t;
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(struct node* p, int index)
{
	struct node* q = NULL;
	int i, x = -1;

	if (index < 1 || index>length(p))
		return x;
	else
	{
		if (index == 1)
		{
			x = p->data;
			first = first->next;
			free(p);
		}
		else
		{
			for (i = 0; i < index - 1; i++)
			{
				q = p;
				p = p->next;
			}
			q->next = p->next;
			x = p->data;
			free(p);
		}
		return x;
	}
}

int issorted(struct node* p)
{
	int x = INT_MIN;
	while (p != NULL)
	{
		if (p->data < x)
			return 0;
		x = p->data;
		p = p->next;
	}
	return 1;
}

void removeduplicate(struct node* p)
{
	struct node* q = p->next;

	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

void reverse1(struct node* p)
{
	int* A,i=0;
	struct node* q=p;
	A = (int*)malloc(sizeof(int) * length(p));

	while (q != NULL)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while (q != NULL)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}
}

void reverse2(struct node* p)
{
	struct node* q = NULL, * r = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

void reverse3(struct node* q, struct node* p)
{
	if (p)
	{
		reverse3(p, p->next);
		p->next = q;
	}
	else
	{
		first = q;
	}
}
void concat(struct node* p, struct node* q)
{
	third = p;
	while (p->next)
		p = p->next;
	p->next = q;
}

void merge(struct node* p, struct node* q)
{
	struct node* last = NULL;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		last->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		last->next = NULL;
	}
	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if (p)
		last->next = p;
	else
		last->next = q;
}

int isloop(struct node* f)
{
	struct node* p, * q;
	p = q = f;

	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while (p && q && p != q);

	if (p == q)
		return 1;
	else
		return 0;
}

int main()
{
	struct node* temp;
	struct node* t1, * t2;

	int A[] = { 10,20,30,40,50 };
	int B[] = { 5,15,25,35,45 };
	create(A, 5);

	t1 = first->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;

	create2(B, 5);
	display(first);
	printf("\n");
	display(second);
	printf("\n");
	Rdisplay(first);
	printf("\n");
	printf("Length=%d\n", length(first));
	printf("Length=%d\n", Rlength(first));
	printf("Sum=%d\n", add(first));
	printf("Sum=%d\n", Radd(first));
	printf("Maximum element=%d\n", Max(first));
	printf("Maximum element=%d\n", RMax(first));
	temp = improvedsearch(first, 1);
	if (temp != NULL)
		printf("%d element found\n", temp->data);
	else
		printf("Element not found\n");
	display(first);
	printf("\n");
	insert(first, 5, 12);
	display(first);
	printf("\n");
	sortedinsert(first, 5);
	display(first);
	printf("\n");
	printf("%d is deleted\n", Delete(first, 7));
	display(first);
	printf("\n");
	if (issorted(first))
		printf("Sorted List\n");
	else
		printf("Not Sorted\n");
	removeduplicate(first);
	display(first);
	printf("\n");
	reverse3(NULL, first);
	display(first);
	printf("\n");
	concat(first, second);
	display(third);
	printf("\n");
	merge(first, second);
	display(third);
	printf("\n");
	printf("%d", isloop(first));

	

	return 0;
}