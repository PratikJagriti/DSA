#include<stdio.h>
#include<stdlib.h>

void create(int a[], int n)
{
	printf("Enter all the elements of the matrix:\n");
	int i, j, x;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf_s("%d", &x);
			if (i == j)
				a[i - 1] = x;
		}
	}
}

void set(int a[], int i, int j, int x)
{
	if (i == j)
		a[i - 1] = x;
}

void get(int a[], int i, int j)
{
	if (i == j)
		printf("%d", a[i - 1]);
	printf("0");
}

void display(int a[], int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				printf("%d ", a[i - 1]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	int* a, n, ch, i, j, x;
	printf("Enter dimention:");
	scanf_s("%d", &n);
	a = (int*)malloc(n * sizeof(int));

	do {
		//Display menu
		printf("Menu\n");
		printf("1.Create\n2.Set\n3.Get\n4.Display\n");
		printf("Enter your choice:");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1:
			create(a, n);
			break;
		case 2:
			printf("Enter the indices and element:\n");
			scanf_s("%d%d%d", &i, &j, &x);
			set(a, i, j, x);
			break;
		case 3:
			printf("Enter the indices\n");
			scanf_s("%d%d", &i, &j);
			get(a, i, j);
			break;
		case 4:
			display(a, n);
		}
	} while (ch < 5);
}