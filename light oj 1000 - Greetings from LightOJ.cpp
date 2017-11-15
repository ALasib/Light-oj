#include<stdio.h>
int main()
{
int a,b,n,i;
while((scanf("%d",&n))==1)
{
   for(i=1;i<=n;i++)
   {
       scanf("%d%d",&a,&b);
       if((a<=10)&&(b<=10))
       printf("Case %d: %d\n",i,a+b);
   }
   break;
 
}
 
    return 0;
}
 
