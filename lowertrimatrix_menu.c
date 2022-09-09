#include<stdio.h>
#include<stdlib.h>

void create(int a[], int n)
{
	int i, j, x;
	printf("Enter all the elements:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf_s("%d", &x);
			if (i >= j)
				a[i * (i - 1) / 2 + j - 1] = x;
		}
	}
}

void set(int a[], int i, int j, int x)
{
	if (i >= j)
		a[i * (i - 1) / 2 + j - 1] = x;
}

void get(int a[], int i, int j)
{
	if (i >= j)
		printf("%d\n", a[i * (i - 1) / 2 + j - 1]);
	else
		printf("0\n");
}

void display(int a[], int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i >= j)
				printf("%d ", a[i * (i - 1) / 2 + j - 1]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	int* a, n, ch, i, j, x;
	printf("Enter the dimention:");
	scanf_s("%d", &n);
	a = (int*)malloc((n * (n + 1) / 2) * sizeof(int));
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
			printf("Enter the indices and the element\n");
			scanf_s("%d%d%d", &i, &j, &x);
			set(a, i, j, x);
			break;
		case 3:
			printf("Enter the indices:\n");
			scanf_s("%d%d", &i, &j);
			get(a, i, j);
			break;
		case 4:
			display(a, n);
		}
	} while (ch < 5);
}