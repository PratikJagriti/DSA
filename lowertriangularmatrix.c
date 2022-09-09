#include<stdio.h>
#include<stdlib.h>

struct matrix
{
    int *a;
    int n;
};

void set(struct matrix* m, int i, int j, int x)
{
    if (i >= j)
        m->a[i * (i - 1) / 2 + j - 1] = x;
}

int get(struct matrix m, int i, int j)
{
    if(i>=j)
        return  m.a[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.a[i * (i - 1) / 2 + j - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int i, j, x;
    struct matrix m;
    printf("Enter the dimention:");
    scanf_s("%d", &m.n);
    m.a = (int*)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter all the elements:\n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
                scanf_s("%d", &x);
                set(&m, i, j, x);
        }
    }
    printf("\n\n");
    display(m);
    return 0;
}