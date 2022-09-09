#include<stdio.h>
#include<stdlib.h>

int findMax(int A[], int n)
{
	int i, max = INT_MIN;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

void CountSort(int A[], int n)
{
	int i, j, max;
	int* C;
	max = findMax(A, n);

	C = (int*)malloc(sizeof(int) * (max + 1));

	for (i = 0; i <= max; i++)
		C[i] = 0;

	for (i = 0; i < n; i++)
		C[A[i]]++;

	i = 0;
	j = 0;
	while (i <= max)
	{
		if (C[i] > 0)
		{
			A[j++] = i;
			C[i]--;
		}
		else
			i++;
	}

}

int main()
{
	int A[] = { 5,3,2,7,4,1,0,9,8,6 };
	int i, n = 10;

	CountSort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}