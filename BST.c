#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* lchild;
	int data;
	struct node* rchild;
}*root=NULL;

void insert(int key)
{
	struct node* r = NULL,*t=root, * p;

	if (t == NULL)
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	
	while (t)
	{
		r = t;
		if (key < t->data)
			t = t->lchild;
		else if (key > t->data)
			t = t->rchild;
		else
			return;
	}
	p = (struct node*)malloc(sizeof(struct node));
	p->data = key;
	p->lchild = p->rchild = NULL;

	if (key < r->data)
		r->lchild = p;
	else
		r->rchild = p;
}

void inorder(struct node* p)
{
	if (p)
	{
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

struct node* search(int key)
{
	struct node* t = root;

	while (t)
	{
		if (key < t->data)
			t = t->lchild;
		else if (key > t->data)
			t = t->rchild;
		else
			return t;
	}
	return NULL;
}

int main()
{
	struct node* temp;
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);

	inorder(root);
	printf("\n");

	temp = search(2);
	if (temp)
		printf("element %d found\n", temp->data);
	else
		printf("enlement not found\n");

	return 0;
}