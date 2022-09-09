#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

//Implementing LL functions

void sortedinsert(struct node** H, int key)
{
	struct node* t, * q = NULL, * p = *H;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = key;
	t->next = NULL;

	if (*H == NULL)
		*H = t;
	else
	{
		while (p && p->data < key)
		{
			q = p;
			p = p->next;
		}
		if (p == *H)
		{
			t->next = p;
			*H = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

struct node* search(struct node* H[], int key)
{
	struct node* p = H[hash(key)];
	while (p && p->data != key)
	{
		p = p->next;
	}
	return p;
}

//Implementing hashing

int hash(int key)
{
	return key % 10;
}

void insert(struct node* H[], int key)
{
	int index = hash(key);
	sortedinsert(&H[index], key);
}

int main()
{
	struct node* HT[10];
	struct node* temp;
	int i;

	for (i = 0; i < 10; i++)
	{
		HT[i] = NULL;
	}

	insert(HT, 12);
	insert(HT, 42);
	insert(HT, 25);
	insert(HT, 32);
	insert(HT, 128);
	insert(HT, 15);


	temp = search(HT, 42);
	if (temp != NULL)
	{
		printf("\nKey %d found\n", temp->data);
	}
	else
	{
		printf("\nKey NOT found\n");
	}
}

