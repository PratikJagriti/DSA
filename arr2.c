#include<stdio.h>
int main()
{
    int a[20],i,n,temp,b;
    printf("Enter the number of elements of the array:\n");
    scanf("%d",&n);
    b=n;
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("The elements of the array are:\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-1];
        a[n-1]=temp;
        n--;
    }
    printf("\nReversed array is:\n");
    for(i=0;i<b;i++)
    printf("%d ",a[i]);
}