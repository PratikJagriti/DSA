#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* lchild;
	int data;
	struct node* rchild;
}*root = NULL;

void insert(int key)
{
	struct node* r = NULL, * t = root, * p;

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

struct node* Rinsert(struct node*p, int key)
{
	if (p == NULL)
	{
		struct node* t;
		t = (struct node*)malloc(sizeof(struct node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
		p->lchild = Rinsert(p->lchild, key);
	else if (key > p->data)
		p->rchild = Rinsert(p->rchild, key);
	return p;
}

int Height(struct node* p)
{
	int x, y;
	if (p)
	{
		x = Height(p->lchild);
		y = Height(p->rchild);
		return x > y ? x + 1 : y + 1;
	}
	return 0;
}

struct node* InPre(struct node* p)
{
	while (p && p->rchild != NULL)
		p = p->rchild;
	return p;
}

struct node* InSucc(struct node* p)
{
	while (p && p->lchild != NULL)
		p = p->lchild;
	return p;
}


struct node* Delete(struct node* p, int key)
{
	struct node* q;

	if (p == NULL)
		return NULL;
	if (p->lchild==NULL && p->rchild == NULL && p->data == key)
	{
		if (p == root)
			root = NULL;
		free(p);
		return NULL;
	}
	if (key < p->data)
		p->lchild = Delete(p->lchild, key);
	else if (key > p->data)
		p->rchild = Delete(p->rchild, key);
	else
	{
		if (Height(p->lchild) > Height(p->rchild))
		{
			q = InPre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			q = InSucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	return p;
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
	root=Rinsert(root,10);
	Rinsert(root,50);
	Rinsert(root,20);
	Rinsert(root,40);
	Rinsert(root,30);

	Delete(root, 10);

	inorder(root);
	printf("\n");

	temp = search(10);
	if (temp)
		printf("element %d found\n", temp->data);
	else
		printf("enlement not found\n");

	return 0;
}