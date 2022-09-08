#include <stdio.h>

int main()
{
    int k,i,n,x,t,sum=0,j,val=0;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d%d",&n,&x,&t);
        val=(int)(t/x);
        
        if(val > n)
            val=n;
            
        for(j=val;j>0;j--)
            sum=sum+(val-j);
            
        if(val<n)
        {
            n=n-val;
            for(j=n;j>0;j--)
                sum=sum+val;
        }
        
        printf("%d",sum);
    }

    return 0;
}