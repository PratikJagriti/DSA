#include<stdio.h>

double e(double x, int n)
{
	static double r = 1;
	if (n == 0)
		return r;
	else
	{
		r = 1 + (x / n) * r;
		return e(x, n - 1);
	}
}
int main()
{
	printf("%lf\n", e(1, 10));
}