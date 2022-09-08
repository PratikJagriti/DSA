#include<stdio.h>
#include<math.h>
int main()
{
    int i, n;
    float sum=0, mean, stdev=0, a[20],*ptr;
    printf("Enter the number of elements in the array :");
    scanf("%d",&n);
    ptr=a;
    printf("Enter %d elements of the array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",ptr+i);
    }
    ptr=a;

    //sum of array elements
    for(i=0;i<n;i++)
    {
        sum+=*(ptr+i);
    }
    printf("The sum of array elements is %f",sum);
    ptr=a;

    //mean of array
    mean=sum/n;
    printf("\nThe mean of array elements is %f",mean);

    //standard deviation
    for(i=0;i<n;i++)
    {
      stdev=stdev+pow((*(ptr+i)-mean),2);
    }
    printf("\nStandard deviation is %f",sqrt(stdev/n));
    return 0;
}