#include<stdio.h>

void Merge(int A[], int l, int mid, int h)
{
	int B[100];
	int i, j, k;
	i = l;
	j = mid + 1;
	k = l;

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

	for (i = l; i <= h; i++)
		A[i] = B[i];
}

void RMergeSort(int A[], int l, int h)
{
	if (l < h)
	{
		int mid = (l + h) / 2;
		RMergeSort(A, l, mid);
		RMergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

int main()
{
	int i, n;
	int A[] = { 0,4,7,5,1,3,9,8,6,2 };
	n = 10;

	RMergeSort(A, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}