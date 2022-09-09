#include<stdio.h>

int partition(int A[], int l, int h)
{
	int i, j, temp;
	int pivot = l;
	i = l; j = h;

	while (i < j)
	{
		while (i <= h && A[i] <= A[pivot])
			i++;
		while (j >= l && A[j] > A[pivot])
			j--;

		if (i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[pivot];
	A[pivot] = A[j];
	A[j] = temp;

	return j;
}

void quicksort(int A[], int l, int h)
{
	int j;
	if (l < h)
	{
		j = partition(A, l, h);
		quicksort(A, l, j - 1);
		quicksort(A, j + 1, h);
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
	quicksort(A, 0, n - 1);
	printf("The sorted elements are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}