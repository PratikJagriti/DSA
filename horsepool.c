#include<stdio.h>
#include<string.h>
#define MAX 256

int t[MAX];

void shifttable(char p[])
{
	int i;
	int m = strlen(p);

	for (i = 0; i < MAX; i++)
		t[i] = m;
	for (i = 0; i < m-1 ; i++)
		t[p[i]] = m - i - 1;
}

int horsepool(char src[], char p[])
{
	int i, m, n, k;
	m = strlen(p);
	n = strlen(src);
	printf("Length of the source string is %d\n", n);
	printf("Length of the pattern string is %d\n", m);

	i = m - 1;
	while (i < n)
	{
		k = 0;
		while (k < n && src[i - k] == p[m - k - 1])
			k++;
		if (k == m)
		{
			return i - m + 1;
		}
		else
		{
			i = i + t[src[i]];
		}
	}
	return -1;
}

int main()
{
	char src[20], p[20];
	int h;
	printf("Enter the source string :");
	gets(src);
	printf("Enter the pattern string :");
	gets(p);
	shifttable(p);
	h = horsepool(src, p);

	if (h >= 0)
		printf("Pattern string found in source string at position %d", h+1);
	else
		printf("Pattern string not found in source string\n");
}