#include<stdio.h>

int partition(int A[], int l, int h)
{
	int i = l, j = h, temp;
	int pivot = A[l];

	do
	{
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);

		if(i<j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}

	} while (i < j);

	A[l] = A[j];
	A[j] = pivot;
	return j;
}

void Quick_sort(int A[], int l, int h)
{
	if (l < h)
	{
		int j = partition(A, l, h);
		Quick_sort(A, l, j);
		Quick_sort(A, j + 1, h);
	}
}

int main()
{
	int A[] = { 4, 6, 2, 7, 3, 5, 1, 8, 9, 0, _CRT_INT_MAX };
	int n = 11, i;
	Quick_sort(A, 0, n - 1);

	for (i = 0; i < n - 1; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}