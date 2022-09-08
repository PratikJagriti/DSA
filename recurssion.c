#include<stdio.h>
int fact(int n);
int fact(int n)
{
    if(n==1)
    return n;
    else
    return n*fact(n-1);
}
int main()
{
   int n, res;
   printf("Enter the value of n:");
   scanf("%d",&n);
   res=fact(n);
   printf("Factorial of %d is: %d",n,res);
}