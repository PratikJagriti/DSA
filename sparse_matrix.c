#include<stdio.h>
#include<stdlib.h>

struct element
{
	int i;
	int j;
	int x;
};

struct sparse
{
	int m;
	int n;
	int num;
	struct element* e;
};

void create(struct sparse* s)
{
	int i;
	printf("Enter the dimention:");
	scanf_s("%d%d", &s->m, &s->n);
	printf("Enter the number of non zero elments:");
	scanf_s("%d", &s->num);
	s->e = (struct element*)malloc(s->num * sizeof(struct element));
	printf("Enter non zero elements of the sparse matrix:\n");
	for (i = 0; i < s->num; i++)
	{
		scanf_s("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
	}
}

void display(struct sparse s)
{
	int i, j, k=0;
	for (i = 0; i < s.m; i++)
	{
		for (j = 0; j < s.n; j++)
		{
			if (i == s.e[k].i && j == s.e[k].j)
				printf("%d ", s.e[k++].x);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

struct sparse* add(struct sparse* s1, struct sparse* s2)
{
	int i, j, k;
	i = j = k = 0;
	struct sparse* s3;
	if (s1->m != s2->m || s1->n != s2->n)
		return NULL;
	s3 = (struct sparse*)malloc(sizeof(struct sparse));
	s3->e = (struct element*)malloc((s1->num + s2->num) * sizeof(struct element));

	while (i < s1->num && j < s2->num)
	{
		if (s1->e[i].i < s2->e[j].i)
			s3->e[k++] = s1->e[i++];
		else if (s1->e[i].i > s2->e[j].i)
			s3->e[k++] = s2->e[j++];
		else
		{
			if (s1->e[i].j < s2->e[j].j)
				s3->e[k++] = s1->e[i++];
			else if (s1->e[i].j > s2->e[j].j)
				s3->e[k++] = s2->e[j++];
			else
			{
				s3->e[k] = s1->e[i];
				s3->e[k++].x = s1->e[i++].x + s2->e[j++].x;
			}
		}
	}
	for (; i < s1->num; i++)
		s3->e[k++] = s1->e[i];
	for (; j < s2->num; j++)
		s3->e[k++] = s2->e[j];

	s3->m = s1->m;
	s3->n = s1->n;
	s3->num = k;

	return s3;
}

int main()
{
	struct sparse s1, s2, *s3;

	create(&s1);
	create(&s2);

	s3 = add(&s1, &s2);

	printf("First Matrix:\n");
    display(s1);
	printf("Second Matrix:\n");
	display(s2);
	printf("Sum Matrix:\n");
	display(*s3);

	return 0;
}