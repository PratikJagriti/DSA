#include<stdio.h>

void merge(int A[], int l, int mid, int h)
{
	int i, j, k, B[100];
	i = k = l;
	j = mid + 1;

	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}

	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];

	for (k = l; k <= h; k++)
	{
		A[k] = B[k];
	}
}

void mergesort(int A[], int l, int h)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		mergesort(A, l, mid);
		mergesort(A, mid + 1, h);
		merge(A, l, mid, h);
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
	mergesort(A,0, n-1);
	printf("The sorted elements are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}