#include<stdio.h>
#include<stdlib.h>

void main()
{
    int t, size, B, i, j, min, k;
    scanf_s("%d", &t);
    int* a;
    for (i = 0; i < t; i++)
    {
        scanf_s("%d%d", &size, &B);
        a = (int*)malloc(sizeof(int) * size);
        for (j = 0; j < size; j++)
        {
            scanf_s("%d", &a[j]);
        }
        int count = 0, sum = 0;
        while ((B - sum) >= 0)
        {
            min = a[0];
            for (j = 1; j < size; j++)
            {
                if (a[j] < min)
                {
                    min = a[j];
                    k = j;
                }
            }
            sum = sum + min;
            a[k] = 1001;
            count++;

        }
        printf("Case #%d: %d\n", i + 1, count - 1);

    }
}