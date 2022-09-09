#include<stdio.h>

void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Selection_Sort(int A[], int n)
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		for (j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
			{
				k = j;
			}
		}
		Swap(&A[i], &A[k]);
	}
}

int main()
{
	int A[] = { 3,6,2,1,7,8,4,0 };
	int n = 8, i;

	Selection_Sort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}