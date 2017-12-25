#include<stdio.h>
#include<math.h>
#define gama 0.57721566490
 
double arr[1000005];
int main()
{
    int test,x,n,i,caseno=0;
    double sum,sum2,k;
    sum=0;
    for ( i = 1; i <= 1000000; i++)
        {
          sum += 1.0 / i;
          arr[i] = sum;
       }
   scanf("%d", &test);
 
   while(test--)
   {
       scanf("%d", &n);
        if(n <= 1000000)
            printf("Case %d: %.9lf\n", ++caseno, arr[n]);
        else
        {
            k=n+0.5;
            sum2=log(k)+gama;
            printf("Case %d: %.9lf\n", ++caseno,sum2);
        }
 
   }
    return 0;
}
