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

struct stack
{
	int size;
	int top;
	struct node** S;
};

void stackcreate(struct stack* st,int size)
{
	st->size = size;
	st->top = -1;
	st->S = (struct node**)malloc(st->size * sizeof(struct node*));
}

void stackpush(struct stack* st, struct node *x)
{
	if (st->top == st->size - 1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

struct node* stackpop(struct stack* st)
{
	struct node* x = NULL;
	if (st->top == -1)
		printf("Stack Underflow\n");
	else
		x = st->S[st->top--];
	return x;
}

int stackisEmpty(struct stack st)
{
	if (st.top == -1)
		return 1;
	else
		return 0;
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

void Preorder(struct node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Inorder(struct node* p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

void Postorder(struct node* p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ", p->data);
	}
}

void IPreorder(struct node* t)
{
	struct stack st;
	stackcreate(&st, 100);

	while (t || !stackisEmpty(st))
	{
		if (t)
		{
			printf("%d ", t->data);
			stackpush(&st, t);
			t = t->lchild;
		}
		else
		{
			t = stackpop(&st);
			t = t->rchild;
		}
	}
}

void IInorder(struct node* t)
{
	struct stack st;
	stackcreate(&st, 100);

	while (t || !stackisEmpty(st))
	{
		if (t)
		{
			stackpush(&st, t);
			t = t->lchild;
		}
		else
		{
			t = stackpop(&st);
			printf("%d ", t->data);
			t = t->rchild;
		}
	}
}

void IPostorder(struct node* t)
{
	struct stack st;
	long int temp;
	stackcreate(&st, 100);

	while (t || !stackisEmpty(st))
	{
		if (t)
		{
			stackpush(&st, t);
			t = t->lchild;
		}
		else
		{
			temp = stackpop(&st);
			if (temp > 0)
			{
				stackpush(&st,(struct node*)(-temp));
				t = ((struct node*)(temp))->rchild;
			}
			else
			{
				printf("%d ", ((struct node*)(-temp))->data);
				t = NULL;
			}
		}
	}
}

int main()
{
	Treecreate();
	printf("\nIterative Preorder :");
	IPreorder(root);
	printf("\nIterative Inorder :");
	IInorder(root);
	printf("\nIterative Postorder :");
	IPostorder(root);


	return 0;
}