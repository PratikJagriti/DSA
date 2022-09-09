#include<stdio.h>

void Insert(int A[], int n)
{
	int i = n, temp = A[n];
	while (i > 1 && temp > A[i / 2])
	{
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = temp;
}

void Delete(int A[], int n)
{
	int x, i, j, temp;
	x = A[1];
	A[1] = A[n];
	i = 1;
	j = 2 * i;

	while (j <= n - 1)
	{
		if (j < (n - 1) && A[j + 1] > A[j])
			j = j + 1;
		if (A[i] < A[j])
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i = j;
			j = j * 2;
		}
		else
			break;
	}
	A[n] = x;
}

int main()
{
	int i;
	int H[] = { 0,10,20,30,25,5,40,35 };

	for(i=2;i<=7;i++)
		Insert(H, i);

	for (i = 7; i > 1; i--)
		Delete(H, i);

	for (i = 1; i <= 7; i++)
	{
		printf("%d ", H[i]);

	}
}