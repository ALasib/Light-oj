#include<stdio.h>
#include<math.h>
#define mxn 1000001
double fact[mxn];
 
int main()
{
    int i,n,base,test,caseno=0;
 
    double k;
 
    for( i=1;i<=mxn;i++)
        {
        fact[i]=fact[i-1]+log(i+0.0);
    }
 
    scanf("%d",&test);
   while(test--)
        {
        scanf("%d%d",&n,&base);
        k=(floor(fact[n]/log(base*1.0)+1));
       printf("Case %d: %.0lf\n",++caseno,k);
        }
    return 0;
}
 
 /*log(n!)=log(1*2*....*n)
          =log(1)+log(2)+...+log(n)
   no of digits in (log(n!))= floor(log(n!)/(log(base*1.0))+1
   */
