#include<stdio.h>

double e(double x, int n)
{
	int i;
	double r = 1;
	double num = 1, den = 1;

		for (i = 1; i <=n; i++)
		{
			num *= x;
			den *= i;
			r = r + num / den;
		}
		return r;
}

int main()
{
	printf("%lf\n", e(1, 10));
}