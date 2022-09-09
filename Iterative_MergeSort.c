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

void IMergeSort(int A[], int n)
{
	int l, h, mid, k, i;
	
	for (k = 2; k <= n; k = k * 2)
	{
		for (i = 0; i + k <= n; i = i + k)
		{
			l = i;
			h = i + k - 1;
			mid = (l + h) / 2;

			Merge(A, l, mid, h);
		}
	}
	if (k / 2 < n)
		Merge(A, 0, (k / 2)-1, n - 1);
}

int main()
{
	int i, n;
	int A[] = { 0,4,7,5,1,3,9,8,6,2 };
	n = 10;

	IMergeSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ",A[i]);
	printf("\n");

}