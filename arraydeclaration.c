#include<stdio.h>

int main()
{
	int A[5];
	int B[5] = { 1,2,3,4,5 };
	int C[5] = { 3,4 };
	int D[5] = { 0 };
	int E[] = { 1,2,3,4,5,6 };
	
	int i;
	for (i = 0; i < 5; i++)
		printf("%d\n", &A[i]);
}