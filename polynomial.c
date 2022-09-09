#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct term
{
	int coeff;
	int exp;
};

struct poly
{
	int n;
	struct term* t;
};

void create(struct poly* p)
{
	int i;
	printf("Enter the number of terms:");
	scanf_s("%d", &p->n);
	p->t = (struct term*)malloc(p->n * (sizeof(struct term)));
	printf("Enter the coefficient and terms:\n");
	for (i = 0; i < p->n; i++)
		scanf_s("%d%d", &p->t[i].coeff, &p->t[i].exp);
}

void display(struct poly p)
{
	int i;
	for (i = 0; i < p.n; i++)
		printf("%dx%d + ", p.t[i].coeff, p.t[i].exp);
}

int evaluale(struct poly p)
{
	int sum = 0, x, i;
	printf("Enter the vlaue of x:");
	scanf_s("%d", &x);
	for (i = 0; i < p.n; i++)
		sum += p.t[i].coeff * pow(x, p.t[i].exp);
	return sum;
}

struct poly* add(struct poly* p1, struct poly* p2)
{
	int i, j, k;
	i = j = k = 0;
	struct poly* p3;
	p3 = (struct poly*)malloc(sizeof(struct poly));
	p3->t = (struct term*)malloc((p1->n + p2->n) * (sizeof(struct term)));
	
	while (i < p1->n && j < p2->n)
	{
		if (p1->t[i].exp > p2->t[j].exp)
			p3->t[k++] = p1->t[i++];
		else if (p1->t[i].exp < p2->t[j].exp)
			p3->t[k++] = p2->t[j++];
		else
		{
			p3->t[k].exp = p1->t[i].exp;
			p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
		}
	}
	for (; i < p1->n; i++)
		p3->t[k++] = p1->t[i];
	for (; j < p2->n; j++)
		p3->t[k++] = p2->t[j];

	p3->n = k;

	return p3;
}

int main()
{
	struct poly p1, p2, * p3;
	create(&p1);
	create(&p2);
	p3 = add(&p1, &p2);

	display(p1);
	printf("\n");
	display(p2);
	printf("\n");
	display(*p3);

	printf("%d", evaluale(p1));

	return 0;
}