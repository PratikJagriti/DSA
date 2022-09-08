//To find sum
 
int add(int a, int b)
  {
      int sum=a+b;
      return sum;
  }
#include<stdio.h>
int main()
  {
      int a, b, sum;
      printf("Enter the value of a and b:\n");
      scanf("%d%d",&a,&b);
      sum=add(a,b);
      printf("Sum=%d",sum);
      return 0;
  }    