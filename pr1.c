#include<stdio.h>

#define MAX_SIZE 4

int Q[MAX_SIZE], f, r;
f = -1; r = -1;

void main()
{
	int ch;

	void Insert();
	void Delete();
	void Display();

	while (1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nenter your choice\n");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1: Insert();
			break;
		case 2: Delete();
			break;
		case 3: Display();
			break;
		case 4: printf("\nBye!!!See you next time\n\n");
			exit(0);
		default: printf("\nInvalid choice, try again\n");
		}
	}
}

void Insert()
{
	int x;
	if (r >= MAX_SIZE - 1)
		printf("\nstack overflow\n");
	else
	{
		printf("\nenter the element to be inserted\n");
		scanf_s("%d", &x);

		r++;
		Q[r] = x;

		if (f == -1)
			f = 0;

		printf("the inserted element is %d", x);
	}
}

void Delete()
{
	if (f == -1)
		printf("\nqueue underflow\n");
	else
	{
		int temp;
		temp = Q[f];

		if (f == r)
			f = r = -1;
		else
			f++;

		printf("the deleted element is %d", temp);
	}
}

void Display()
{
	int i;
	if (f == -1)
		printf("no elements to display\n");
	else
	{
		printf("\nthe elements of queue are: ");
		for (i = f; i <= r; i++)
			printf("%d ", Q[i]);
		printf("\n");
	}
}