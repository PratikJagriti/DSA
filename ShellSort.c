#include<stdio.h>

void ShellSort(int A[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = A[i];
			j = i - gap;

			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];
				j -= gap;
			}
			A[j + gap] = temp;
		}
	}
}

int main()
{
	int i, n;
	int A[] = { 6,3,9,12,8,32,7,0,1,5 };
	n = 10;

	ShellSort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}