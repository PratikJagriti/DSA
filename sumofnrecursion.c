#include<stdio.h>

int sum(int n)
{
	if (n == 0)
		return 0;
	else
		return n + sum(n - 1);
}
int main()
{
	int r,a;
	printf("Enter a number:");
	scanf_s("%d", &a);
	r = sum(a);
	printf("%d\n", r);
	return 0;
}