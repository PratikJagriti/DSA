#include<stdio.h>
#include<math.h>

void nqueen(int k, int n);
int place(int k, int i);

int x[20], count = 0;

int main()
{
	int n;
	printf("Enter the number of queens:");
	scanf_s("%d", &n);
	nqueen(1, n);
	if (count == 0)
	{
		printf("No solution exist for %d queens\n", n);
	}
}

void nqueen(int k, int n)
{
	int i, p, q;

	for (i = 1; i <= n; i++)
	{
		if (place(k, i))
		{
			x[k] = i;
			if (k == n)
			{
				count++;
				printf("Solution %d:\n", count);
				for (p = 1; p <= n; p++)
				{
					for (q = 1; q <= n; q++)
					{
						if (x[p] == q)
							printf("Q ");
						else
							printf("X ");
					}
					printf("\n");
				}
			}
			else
				nqueen(k + 1, n);
		}
	}
}

int place(int k, int i)
{
	int j;

	for (j = 1; j < k; j++)
	{
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
			return 0;
	}
	return 1;
}