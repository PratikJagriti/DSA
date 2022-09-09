#include<stdio.h>

void InsertionSort(int A[], int n)
{
	int i, j, x;
	for (i = 1; i < n - 1; i++)
	{
		j = i - 1;
		x = A[i];
		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

int main()
{
	int i, n;
	int A[] = { 4,6,2,7,9,23,12,78 };
	n = 8;

	InsertionSort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}