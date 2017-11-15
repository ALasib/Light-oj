#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int test,i=0;
    double a,b,c,Ratio,x,result,e = pow(10,-6);
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>c>>Ratio;
         x = Ratio/(Ratio+1);
        result = a*sqrt(x);
        printf("Case %d: %lf\n",++i,result);
 
    }
    return 0;
}
