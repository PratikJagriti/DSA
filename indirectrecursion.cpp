#include<stdio.h>

void funA(int a);
void funB(int b);

void funA(int a)
{
	if (a > 0)
	{
		printf("%d ", a);
		funB(a - 1);
	}
}
void funB(int b)
{
	if (b > 1)
	{
		printf("%d ", b);
		funA(b / 2);
	}
}
int main()
{
	funA(20);
}