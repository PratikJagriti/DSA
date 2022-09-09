#include<stdio.h>
#include<math.h>

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}

void knapsack(int v[20][20], int w[20], int p[20], int n, int m)
{
	int i, j;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				v[i][j] = 0;
			}
			else
			{
				if (j < w[i])
					v[i][j] = v[i - 1][j];
				else
					v[i][j] = max((v[i - 1][j]),( (v[i - 1][j - w[i]]) + p[i]));
			}
		}
	}
}

void solution_vector(int v[20][20], int w[], int n, int m)
{
	int i, j, x[20];
	

	printf("The optimal solution is %d\n", v[n][m]);

	for (i = 0; i <= n; i++)
		x[i] = 0;

	i = n; j = m;

	while (i != 0 && j != 0)
	{
		if (v[i][j] != v[i - 1][j])
		{
			x[i] = 1;
			j = j - w[i];
		}
		i--;
	}

	printf("The Solution vector is : ");

	for (i = 1; i <= n; i++)
	{
		printf("%d ", x[i]);
	}
}

void main()
{
	int v[20][20], w[20], p[20], i, j, m, n;

	printf("Enter the number of objects:");
	scanf_s("%d", &n);
	printf("Enter the weight of the objects: ");
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	printf("Enter the price of the objects :");
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &p[i]);
	}
	printf("Enter the capacity of the knapsack: ");
	scanf_s("%d", &m);

	knapsack(v, w, p, n, m);

	printf("The knapsack table is :\n");
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	solution_vector(v, w, n, m);
}