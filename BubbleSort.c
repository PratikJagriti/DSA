#include<stdio.h>

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int A[], int n)
{
	int i, j, flag;

	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				Swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}

int main()
{
	int A[] = { 4,6,3,1,5,9,8,7 }, n = 8, i;
	BubbleSort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");
}