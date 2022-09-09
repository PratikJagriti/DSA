#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* lchild;
	int data;
	struct node* rchild;
}*root = NULL;

struct queue
{
	int size;
	int front;
	int rear;
	struct node** Q;
};

void create(struct queue* q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (struct node**)malloc(q->size * sizeof(struct node*));
}

void enqueue(struct queue* q, struct node* x)
{
	if ((q->rear + 1) % q->size == q->front)
		printf("Queue is full\n");
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x;
	}
}

struct node* dequeue(struct queue* q)
{
	struct node* x = NULL;
	if (q->front == q->rear)
		printf("Queue is empty\n");
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q)
{
	return q.front == q.rear;
}

void Treecreate()
{
	int x;
	struct node* p, * t;
	struct queue q;
	create(&q, 100);

	printf("Enter the root node:");
	scanf_s("%d", &x);
	root = (struct node*)malloc(sizeof(struct node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);

	while (!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter left child of %d :", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct node*)malloc(sizeof(struct node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			enqueue(&q, t);
			p->lchild = t;
		}

		printf("Enter right child of %d :", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct node*)malloc(sizeof(struct node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			enqueue(&q, t);
			p->rchild = t;
		}
	}
}

int count(struct node* root)
{
	if (root)
		return count(root->lchild) + count(root->rchild) + 1;
	return 0;
}

int height(struct node* root)
{
	int x = 0, y = 0;
	if (root)
	{
		x = height(root->lchild);
		y = height(root->rchild);
		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
	return 0;
}

int main()
{
	Treecreate();
	printf("Number of nodes of tree is %d\n", count(root));
	printf("Heigh of the tree is %d\n", height(root));
}