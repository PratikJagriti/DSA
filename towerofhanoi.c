#include<stdio.h>

void TOH(int n, int A, int B, int C)
{
	if (n > 0)
	{
		TOH(n-1, A, C, B);
		printf("%d,%d\n", A, C);
		TOH(n - 1, B, A, C);
	}
}
int main()
	{
	printf("Steps to be followed:\n");
	TOH(16, 1, 2, 3);
	}