#include<stdio.h>
#include<string.h>
int main()
{
    int t, n, k;
    char x[100];
    int i, p;

    scanf_s("%d", &t);

    for (i = 1; i <= t; i++)
    {
        int j = 0, count = 0;
        scanf_s("%d%d", &n, &k);
        fgets(x, sizeof(x), stdin);


        for (p = 1; p <= n / 2; p++)
        {
            if (x[p] == x[n - p + 1])
            {
                count++;
            }
        }

        if (count == k)
        {
            printf("Case #%d: 0", i);
        }

        else if (count < k)
        {
            for (p = 1; p <= n / 2; p++)
            {
                if (x[p] != x[n - p + 1])
                {
                    x[p] = x[n - p + 1];
                    count++;
                    j++;
                }
                if (count == k)
                {
                    printf("Case #%d: %d", i, j);
                    break;

                }
            }
        }

        else
        {
            for (p = 1; p <= n / 2; p++)
            {
                if (x[p] == x[n - p + 1])
                {
                    if (x[p] == 90)
                        x[p] = x[p] - 1;
                    else
                        x[p] = x[p] + 1;
                    count--;
                    j++;
                }
                if (count == k)
                {
                    printf("Case #%d: %d", i, j);
                    break;
                }
            }
        }
        printf("\n");
    }
}