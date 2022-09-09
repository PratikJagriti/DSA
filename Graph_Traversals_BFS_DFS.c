#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*front = NULL, * rear = NULL;

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

int isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

void BFS(int G[][8], int start, int n)
{
	int j;
	int visited[8] = { 0 };

	printf("%d ", start);
	visited[start] = 1;
	enqueue(start);

	while (!isEmpty())
	{
		start = dequeue();
		for (j = 1; j < n; j++)
		{
			if (G[start][j] == 1 && visited[j] == 0)
			{
				printf("%d ", j);
				visited[j] = 1;
				enqueue(j);
			}
		}
	}
	
}

void DFS(int G[][8], int start, int n)
{
	int j;
	static int visited[8] = { 0 };

	if (visited[start] == 0)
	{
		printf("%d ", start);
		visited[start] = 1;

		for (j = 1; j < n; j++)
		{
			if (G[start][j] == 1 && visited[j] == 0)
				DFS(G, j, n);
		}
	}
}


int main()
{
	int G[8][8] = { {0,0,0,0,0,0,0,0},
				{0,0,1,1,1,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,0,1,1,0,0},
				{0,1,0,1,0,1,0,0},
				{0,0,0,1,1,0,1,1},
				{0,0,0,0,0,1,0,0},
				{0,0,0,0,0,1,0,0} };

	BFS(G, 4, 8);
	printf("\n");
	DFS(G, 5, 8);

	printf("\n");
}