#include<stdio.h>

void insertion(int A[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		key = A[i];
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

int main()
{
	int i, n;
	int A[20];
	printf("Enter the number of elements:");
	scanf_s("%d", &n);
	printf("Enter the elemtnts:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	insertion(A, n);
	printf("The sorted elements are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}