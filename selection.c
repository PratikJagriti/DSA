#include<stdio.h>

void selection(int A[], int n)
{
	int i, j,k;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (A[k] > A[j])
				k = j;
		}
		int temp = A[i];
		A[i] = A[k];
		A[k] = temp;
	}
}

int main()
{
	int i,n;
	int A[20];
	printf("Enter the number of elements to be sorted:");
	scanf_s("%d", &n);
	printf("Enter the elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	selection(A, n);
	printf("Elements after sorting:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}