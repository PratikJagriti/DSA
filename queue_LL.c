#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct node* t;
	t = (struct node*)malloc(sizeof(struct node));
	if (t == NULL)
		printf("Queue full\n");
	else
	{
		t->data = x;
		t->next = NULL;
		if (front == NULL)
			front = rear = t;
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int dequeue()
{
	int x = -1;
	struct node* t;

	if (front == NULL)
		printf("Queue empty\n");
	else
	{
		x = front->data;
		t = front;
		front = front->next;
		free(t);
	}
	return x;
}

void display()
{
	struct node* t = front;
	while (t)
	{
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
    display();
	printf("%d", dequeue());
	printf("\n");
	display();
	return 0;
}